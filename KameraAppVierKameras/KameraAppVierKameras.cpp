/*
# Imporant
# only quit program with ESC!
# Needs Opencv
# Change counter manually if you make a break
*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
#include <windows.h>

using namespace std;
using namespace cv;

long counterR = 60000, counterL = 60000; // counter to name pictures


int main()
{
    
    time_t start, end;
    start = time(0);
    int n = 5; // Seconds between pictures
    int milliSeconds = n * 1000; 

    Mat myImage, myImage1, myImage2, myImage3;

    namedWindow("Camera 1"); //Declaring a matrix to load the frames
    namedWindow("Camera 2");
    //namedWindow("Camera 3");

    VideoCapture cap(0); // opens camera at port 0
    VideoCapture cap1(3);
    //VideoCapture cap2(2);


    if (!cap.isOpened() || !cap1.isOpened()) { // Maybe add cap2 and cap3
        cout << "One Camera is not working" << endl;
        system("pause");
        return -1;
    }

    while (true) {
        cap >> myImage;
        cap1 >> myImage1;
        //cap2 >> myImage2;

        if (myImage.empty()) { 
            break; // breaks loop if video frame is empty
        }

        imshow("Camera 1", myImage); //Showing the video
        imshow("Camera 2", myImage1);
        //imshow("Camera 3", myImage2);
        
        // Saves image every n seconds
        if (time(0) - start == n) {
            Beep(1500, 100);
            imwrite("/Users/micha/Desktop/picturesR/" + to_string(counterL) + "R.png", myImage);// Saves an image
            counterR++;
            imwrite("/Users/micha/Desktop/picturesL/" + to_string(counterR) + "L.png", myImage1);
            counterL++;
            //imwrite("/Users/micha/Desktop/pictures/" + to_string(counter) + ".png", myImage2);
            start = start + n;
            //counter++;
        }
        
        char c = (char)waitKey(25); //Allowing 25 milliseconds frame processing time and initiating break condition
        if (c == 27) { break; } // breaks loop if enter is hit
        
        
    } 
    
    
    cap.release(); // release buffer memory
    cap1.release();
    //cap2.release();
    //cap3.release();
    return 0;


}



