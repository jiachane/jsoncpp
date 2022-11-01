#include "track_param.h"

void readFile_writeJson();

int main(int argc, char* argv[])
{
	if (Read_Json()) {
		cout_print();
	}
	
	Write_Json("ZOOM_RATIO", 3.0, 0);
	
	//readFile_writeJson();
	
	
	return 0;
}

void readFile_writeJson()
{ 
	Json::Reader reader;
	Json::Value root;

	fstream in("motor_param.json", ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "Error opening file\n";
		return ;
	}
	if (reader.parse(in, root))
	{
		int DETE_ENABLE_GPIO = root["MOTOR PARAM"]["DETE_ENABLE_GPIO"].asInt();
		cout<<"DETE_ENABLE_GPIO="<<DETE_ENABLE_GPIO<<std::endl;
		int enble_gpio = root["MOTOR PARAM"]["CHANNL0"]["enble_gpio"].asInt();
		cout<<"enble_gpio="<<enble_gpio<<std::endl;
		for(unsigned int i = 0; i < root["MOTOR PARAM"]["CHANNL0"]["speed"].size(); i++)
		{
			int speed_ = root["MOTOR PARAM"]["CHANNL0"]["speed"][i].asInt();
			std::cout<<speed_<<" ";
		}

	}
	else
	{
		cout << "parse error\n" << endl;
	}
	
	in.close();

}


