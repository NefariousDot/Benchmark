#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>

using namespace std;
using namespace cv;

bool try_use_gpu = false;
bool divide_images = false;

Stitcher::Mode mode = Stitcher::PANORAMA;
vector<Mat> imgs;
string result_name = "stiching_result.jpg";

void printUsage(char** argv);
int parseCmdArgs(int argc, char** argv);

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })



int main(int argc, char* argv[])
{
    double instret_start,instret_end,cycle_start,cycle_end;
    instret_start=read_csr(instret);
    cycle_start=read_csr(cycle);

    int retval = parseCmdArgs(argc, argv);
    if (retval) return EXIT_FAILURE;
    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode, try_use_gpu);

    Stitcher::Status status = stitcher->stitch(imgs, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return EXIT_FAILURE;
    }
    
    imwrite(result_name, pano);
    cout << "stitching completed successfully\n" << result_name << " saved!\n";

    cycle_end=read_csr(cycle);
    instret_end=read_csr(instret);

    printf("cycle : %lf\n",(cycle_end-cycle_start));
    printf("instret : %lf\n",(instret_end-instret_start));
    printf("IPC : %lf\n",(instret_end-instret_start)/(cycle_end-cycle_start));

    return EXIT_SUCCESS;
}
void printUsage(char** argv)
{
    cout <<
         "Images stitcher.\n\n" << "Usage :\n" << argv[0] <<" [Flags] img1 img2 [...imgN]\n\n"
         "Flags:\n"
         "  --d3\n"
         "      internally creates three chunks of each image to increase stitching success\n"
         "  --try_use_gpu (yes|no)\n"
         "      Try to use GPU. The default value is 'no'. All default values\n"
         "      are for CPU mode.\n"
         "  --mode (panorama|scans)\n"
         "      Determines configuration of stitcher. The default is 'panorama',\n"
         "      mode suitable for creating photo panoramas. Option 'scans' is suitable\n"
         "      for stitching materials under affine transformation, such as scans.\n"
         "  --output <result_img>\n"
         "      The default is 'result.jpg'.\n\n"
         "Example usage :\n" << argv[0] << " --d3 --try_use_gpu yes --mode scans img1.jpg img2.jpg\n";
}

int parseCmdArgs(int argc, char** argv)
{
    if (argc == 1)
    {
        printUsage(argv);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (string(argv[i]) == "--help" || string(argv[i]) == "/?")
        {
            printUsage(argv);
            return EXIT_FAILURE;
        }

        else if (string(argv[i]) == "--try_use_gpu")
        {
            if (string(argv[i + 1]) == "no")
                try_use_gpu = false;

            else if (string(argv[i + 1]) == "yes")
                try_use_gpu = true;

            else
            {
                cout << "Bad --try_use_gpu flag value\n";
                return EXIT_FAILURE;
            }

            i++;

        }

        else if (string(argv[i]) == "--d3")
        {
            divide_images = true;
        }

        else if (string(argv[i]) == "--output")
        {
            result_name = argv[i + 1];
            i++;
        }

        else if (string(argv[i]) == "--mode")
        {
            if (string(argv[i + 1]) == "panorama")
                mode = Stitcher::PANORAMA;

            else if (string(argv[i + 1]) == "scans")
                mode = Stitcher::SCANS;

            else
            {
                cout << "Bad --mode flag value\n";
                return EXIT_FAILURE;
            }

            i++;

        }

        else
        {
            Mat img = imread(samples::findFile(argv[i]));

            if (img.empty())
            {
                cout << "Can't read image '" << argv[i] << "'\n";
                return EXIT_FAILURE;
            }

            if (divide_images)
            {
                Rect rect(0, 0, img.cols / 2, img.rows);
                imgs.push_back(img(rect).clone());
                rect.x = img.cols / 3;
                imgs.push_back(img(rect).clone());
                rect.x = img.cols / 2;
                imgs.push_back(img(rect).clone());
            }

            else
                imgs.push_back(img);
        }
    }
    
    return EXIT_SUCCESS;
}
