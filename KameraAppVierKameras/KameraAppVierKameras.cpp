/*
# Imporant
# only quit program with ESC 
*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

long counter = 60000; // counter to name pictures

int main()
{
    
    time_t start, end;
    start = time(0);
    int n = 5; // Seconds between pictures
    int milliSeconds = n * 1000; 

    Mat myImage;
    namedWindow("Camera 1"); //Declaring a matrix to load the frames
    VideoCapture cap(0); // opens camera at port 0
    if (!cap.isOpened()) {
        cout << "No Video" << endl;
        system("pause");
        return -1;
    }

    while (true) {
        cap >> myImage;

        if (myImage.empty()) { 
            break; // breaks loop if video frame is empty
        }
        imshow("Camera 1", myImage); //Showing the video

        // Saves image every n seconds
        if (time(0) - start == n) {
            imwrite("/Users/Micha/Desktop/pictures/" + to_string(counter) + ".png", myImage); // Saves an image
            start = start + n;
            counter++;
        }
        
        char c = (char)waitKey(25); //Allowing 25 milliseconds frame processing time and initiating break condition
        if (c == 27) { break; } // breaks loop with esc
        
        
    } 
    
    cap.release(); // release buffer memory
    return 0;


}



