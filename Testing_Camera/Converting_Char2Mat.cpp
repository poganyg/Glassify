const int WIDTH = 800, HEIGHT = 600;

uchar *data = new uchar[WIDTH * HEIGHT * 3];

for (int i = 0; i < WIDTH*HEIGHT*3;i+=3)
{
    if (i < WIDTH*HEIGHT*3/2)
    {
        data[i + 0] = (uchar)0;
        data[i + 1] = (uchar)0;
        data[i + 2] = (uchar)255;
    }
    else
    {
        data[i + 0] = (uchar)255;
        data[i + 1] = (uchar)0;
        data[i + 2] = (uchar)0;
    }
}

cout << "May God be pleased with you, amen!\n";

Mat colorfrm = Mat(HEIGHT, WIDTH, CV_8UC3);
colorfrm.data = data;

while (1)
{
imshow("Original Image", colorfrm);

    /////////

    int c = cvWaitKey(30);
    if (c == ' ')
    {
        break;
    }
    if (c == 'q' || c == 'Q' || c == 27)
    {
        return 0;
    }
}
