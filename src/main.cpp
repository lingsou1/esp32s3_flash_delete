/*
接线说明:无

程序说明:使用闪存文件系统(SPIFFS)来对写入文件进行删除

注意事项:下面的网址中有很多已经写好的函数可以用
(https://github.com/espressif/arduino-esp32/blob/master/libraries/SPIFFS/examples/SPIFFS_Test/SPIFFS_Test.ino)

函数示例:无

作者:灵首

时间:2023_3_12

*/
#include <Arduino.h>
#include <SPIFFS.h>


/*
# brief 启动SPIFFS
# param 无
# retval 无
*/
void SPIFFS_start_init(){
  if(SPIFFS.begin()){
    Serial.print("SPIFFS Start!!!\n");
  }
  else{
    Serial.print("SPIFFS Failed to start!!!\n");
  }
}



/*
# brief   删除指定路径的文件
# param   fs::FS &fs :用SPIFFS
# param   const char * pat :需要删除的文件的路径(如:"/lingsou/notes.txt")
# retval  无
*/
void delete_File(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\r\n", path);
    //SPIFFS.remove()  这个函数应该是在删除闪存文件中的关键函数
    if(fs.remove(path)){
        Serial.println("- file deleted\n");
    } else {
        Serial.println("- delete failed\n");
    }
}


void setup() {
  //开启串口
  Serial.begin(9600);

  //开启SPIFFS
  SPIFFS_start_init();
  Serial.print("SPIFFS working sucessfully!!!\n");

  //删除指定路径的文件
  delete_File(SPIFFS,"/lingsou/notes.txt");
}

void loop() {

}