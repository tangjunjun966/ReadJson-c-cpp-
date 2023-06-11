#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "ReadJson.h"




/* Read a file, parse, render back, etc. */
char* dofile(char* filename)
{
	FILE* f; 
	long length; 
	char* data;

	f = fopen(filename, "rb"); 
	fseek(f, 0, SEEK_END); 
	length = ftell(f); 
	fseek(f, 0, SEEK_SET);
	data = (char*)malloc(length + 1); 
	fread(data, 1, length, f); 
	fclose(f);
	//doit(data);
	//parseJsonText(data);
	//free(data);
	return data;
}


char* process_variate(char* data,char* variate) {
	char* out;
	cJSON* json;
	cJSON* childJson = NULL;

	json = cJSON_Parse(data);
	childJson = cJSON_GetObjectItem(json, variate);
	
	char* result = childJson->valuestring;

	return result;
}




int main(int argc, const char* argv[]) {

	char* file_name = "parameters.json";
	char* data;
	char* variate;

	data=dofile(file_name);

	char* server_ip=process_variate( data, "server_ip");
	char* server_port_temp = process_variate(data, "server_port");
	int server_port = atoi(server_port_temp);
	
	char* rtsp_id_temp = process_variate(data, "rtsp_id");
	int rtsp_id = atoi(rtsp_id_temp);
	char* rtsp_link = process_variate(data, "rtsp_link");
	char* rtsp_user = process_variate(data, "rtsp_user");
	char* rtsp_password = process_variate(data, "rtsp_password");
	char* rtsp_encodeType_temp = process_variate(data, "rtsp_encodeType");
	int rtsp_encodeType = atoi(rtsp_encodeType_temp);
	char* rtsp_buffersize_temp = process_variate(data, "rtsp_buffersize");
	int rtsp_buffersize = atoi(rtsp_buffersize_temp);

	free(data);

	

	

	return 0;
}
