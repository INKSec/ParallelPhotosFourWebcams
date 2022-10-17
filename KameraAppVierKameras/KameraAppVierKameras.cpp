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




int main()
{
    long counterR = 60000, counterL = 60000; // counter to name pictures
    const int width{ 3072 }, height{ 2304 }; // Camera resolution
    const int secondsBetweenPictures = 5;
    //const int milliseconds = secondsBetweenPictures * 1000;
    time_t start, end;
    start = time(0);
    Mat myImage, myImage1, myImage2, myImage3;

    



    namedWindow("Camera 1"); //Declaring a matrix to load the frames
    //namedWindow("Camera 2");
    //namedWindow("Camera 3");
    //namedWindow("Camera 4");

    VideoCapture cap(0); // opens camera at port 0
    //VideoCapture cap1(1);
    //VideoCapture cap2(2);
    //VideoCapture cap2(3);

    cap.set(CAP_PROP_FRAME_WIDTH, width); // sets resolution width
    cap.set(CAP_PROP_FRAME_HEIGHT, height); // sets resolution height


    if (!cap.isOpened()) { // Maybe add cap2 and cap3
        cout << "One Camera is not working" << endl;
        system("pause");
        return -1;
    }

    while (true) {
        cap >> myImage;
        //cap1 >> myImage1;
        //cap2 >> myImage2;
        //cap3 >> myImage3;

        if (myImage.empty()) { 
            break; 
        }

        imshow("Camera 1", myImage); //Showing the video. Is not needed to take pictures
        //imshow("Camera 2", myImage1);
        //imshow("Camera 3", myImage2);
        //imshow("Camera 4", myImage3);
        
        // Saves image every n seconds
        if (time(0) - start == secondsBetweenPictures) {
            Beep(1500, 100);
            imwrite("/Users/Micha/Desktop/picturesL/" + to_string(counterL) + "R.png", myImage);// Saves an image
            counterR++;
            //imwrite("/Users/Micha/Desktop/picturesL/" + to_string(counterR) + "L.png", myImage1);
            counterL++;
            //imwrite("/Users/micha/Desktop/pictures/" + to_string(counter) + ".png", myImage2);
            //imwrite("/Users/micha/Desktop/pictures/" + to_string(counter) + ".png", myImage3);
            start = start + secondsBetweenPictures;
            
        }
        
        char c = (char)waitKey(25); //Allowing 25 milliseconds frame processing time and initiating break condition
        if (c == 27) { break; } // breaks loop with esc
        
        
    } 
    
    
    cap.release(); // release buffer memory
    //cap1.release();
    //cap2.release();
    //cap3.release();
    return 0;


}



