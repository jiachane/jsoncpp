#ifndef TRACK_PARAM_H
#define TRACK_PARAM_H

#include <iostream>
#include <string>
#include <fstream>
#include <json.h>

using namespace std;

bool If_zoom = false;
float zoom_ratio = 1.0;
string stop_direction = "default";
int target_retention_time = 500;
string pan_speed = "default";
string tilt_speed = "default";

static int Read_Json(){
	Json::Reader reader;
	Json::Value root;
	
	fstream in("track_param.json", ios::in | ios::binary);
	if (!in.is_open()){
		std::cout << "Error open Json file \n";
		return 0;
	}
	if (reader.parse(in, root)){
		If_zoom = root["TRACK_PARAM"]["IF_ZOOM"].asBool();
		zoom_ratio = root["TRACK_PARAM"]["ZOOM_RATIO"].asFloat();
		stop_direction = root["TRACK_PARAM"]["STOP_DIRECTION"].asString();
		target_retention_time = root["TRACK_PARAM"]["TARGET_RETENTION_TIME"].asInt();
		pan_speed = root["TRACK_PARAM"]["PAN"]["speed"].asString();
		tilt_speed = root["TRACK_PARAM"]["TILT"]["speed"].asString();
	} else {
		std::cout << "paras error \n";
	}
	in.close();
	
	return 1;
}

template<typename T>
static int Write_Json(string param_key, T param_value, bool pan_tilt){
	Json::Reader reader;
	Json::Value root;
	Json::StyledWriter sw;
	
	fstream in("track_param.json", ios::in | ios::binary);
	if (!in.is_open()){
		std::cout << "Error open Read Json file \n";
		return 0;
	}
	reader.parse(in, root);
	in.close();
	if (!pan_tilt) {
		root["TRACK_PARAM"][param_key] = param_value;
	} else {
		root["TRACK_PARAM"][param_key]["speed"] = param_value;
	}
	
	fstream fout("track_param.json", ios::out | ios::trunc);
	if (!fout.is_open()){
		std::cout << "Error open Write Json file \n";
		return 0;
	}
	
	fout << sw.write(root);
	fout.close();
	
	return 1;
}

static void cout_print(){
	std::cout << "If_zoom = " << If_zoom << "\n" \
	<< "zoom_ratio = " << zoom_ratio << "\n" \
	<< "stop_direction = " << stop_direction << "\n" \
	<< "target_retention_time = " << target_retention_time << "\n" \
	<< "pan_speed = " << pan_speed << "\n" \
	<< "tilt_speed = " << tilt_speed << "\n";
}


#endif  // TRACK_PARAM_H