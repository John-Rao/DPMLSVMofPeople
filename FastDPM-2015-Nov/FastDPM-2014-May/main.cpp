#include "FastDPM.h"
#include <conio.h>

vector<string>  yuStdDirFiles( string DirName, vector<string> FileExtensions );
string trim_file_name( string FileName, int FLAG );

int	main()
{
	/* I. Get images */
	//string	img_dir = "E:/mystu/QTCode/images";
	//string extensions[] = { ".jpg" };
	//vector<string>	img_extensions( extensions, extensions+1 );
	//vector<string>	imgnames = yuStdDirFiles( img_dir, img_extensions );
	//imgnames.clear();
	vector<string> imgnames;
	imgnames.push_back("E:/mystu/QTCode/build-1-5-trainSVM-Desktop_Qt_5_8_0_MinGW_32bit-Debug/test.jpg");
	cout << "qqqqqqqqq" << endl;
	/* II. Perform Part_Model based detection */

	//FastDPM	PM( "model_inria_14_2_features.txt" );
	FastDPM	PM("model_inriaperson.txt");
	//FastDPM	PM("model.txt");

	bool	flag = false;
	for( unsigned i=0; i<imgnames.size(); i++ ){
		string	img_name = imgnames[i];
		cv::Mat	img_uint8 = cv::imread( img_name.c_str() );	
		if( img_uint8.empty() ){
			cout<<"Cannot get image "<<img_name<<endl;
			getchar();
			return -2;
		}
		cout<<"Processing "<<trim_file_name(img_name,0)<<endl;
		cv::Mat	img = PM.prepareImg( img_uint8 );
		PM.detect( img, -1.0f, true, true );	
		cout<<"------------------------------------------------------------"<<endl;
		if( PM.detections.empty() )
			continue;
		flag = true;
		char key = cv::waitKey(30);
		if( key==27 )
			break;
	}
	cout<<"Finished!"<<endl;
	if( flag )
		cv::waitKey();
	else
		_getch();

	return	0;
}