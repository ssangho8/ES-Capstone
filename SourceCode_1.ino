/*#include <HX711.h>
  #include "HX711.h" //Call HX711 LoadCell Library
  #define calibration_factor -7050.0 // Define Initial Value of Load Cell 
  #define DOUT  11 //엠프 데이터 아웃 핀
  #define CLK  10  //엠프 클락
  HX711 scale(DOUT, CLK); //엠프 핀 선언 */
//////////////////////////////////////////Load Cell

#define trig1 2    // Define Trigger Pin
#define echo1 3    // Define Echo Pin
#define trig2 4    
#define echo2 5   
#define trig3 6  
#define echo3 7   
#define trig4 16     
#define echo4 17    
#define trig_top 8     
#define echo_top 9   
#define trig_mot 10    
#define echo_mot 11    
/////////////////////////////////////////////Ultrasonic Sensor

#include "SparkFun_WT2003S_MP3_Decoder.h" // Click here to get the library: http://librarymanager/All#SparkFun_WT2003S

// Defining some status codes from the WT2003S
#define STATUS_PLAY 0x01
#define STATUS_STOP 0x02
#define STATUS_PAUSE 0x03

SoftwareSerial mp3_sws(12, 13);   // Use software serial so that the Arduino hardware serial can be used for control commands
WT2003S MP3;                    // Create an object of the WT2003S class called MP3
bool autoplay = true;
///////////////////////////////////////////////////mp3모듈

#include <Adafruit_NeoPixel.h>
#define PIN_low            14                              // 제어 신호핀
#define NUMPIXELS_low      4                             // 제어하고 싶은 LED 개수
#define PIN_high            18                              // 제어 신호핀
#define NUMPIXELS_high      18                             // 제어하고 싶은 LED 개수

Adafruit_NeoPixel pixels_high = Adafruit_NeoPixel(NUMPIXELS_high, PIN_high, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_low = Adafruit_NeoPixel(NUMPIXELS_low, PIN_low, NEO_GRB + NEO_KHZ800);
//int celayval = 500; // celay for half a second

//////////////////////////////////////////////////////////////////////////////네오픽셀

#include <Servo.h>

Servo myservo;

#define PUMPPIN 15    //peristaltic pump control pin, connect to arduino digital pin 9
#define waitTime 2000 //interval time(ms) between every state
//////////////////////////////////////////////////////////////////////////////펌프

void setup() {
  Serial.begin(9600);
  /*Serial.println("Weight detection start");
    scale.set_scale(calibration_factor);
    scale.tare(); */
  /////////////////////////////////////////////////////////////////////무게센서
  pinMode(trig1, OUTPUT);    // 트리거 핀 출력으로 선언
  pinMode(echo1, INPUT);     // 에코 핀 입력으로 선언
  pinMode(trig2, OUTPUT);    // 트리거 핀 출력으로 선언
  pinMode(echo2, INPUT);     // 에코 핀 입력으로 선언
  pinMode(trig3, OUTPUT);    // 트리거 핀 출력으로 선언
  pinMode(echo3, INPUT);     // 에코 핀 입력으로 선언
  pinMode(trig4, OUTPUT);    // 트리거 핀 출력으로 선언
  pinMode(echo4, INPUT);     // 에코 핀 입력으로 선언
  pinMode(trig_top, OUTPUT);    // 트리거 핀 출력으로 선언
  pinMode(echo_top, INPUT);     // 에코 핀 입력으로 선언
  pinMode(trig_mot, OUTPUT);    // 트리거 핀 출력으로 선언
  pinMode(echo_mot, INPUT);     // 에코 핀 입력으로 선언
  /////////////////////////////////////////////////////////////////초음파센서
  pixels_high.begin(); // This initializes the NeoPixel library.
  pixels_high.setBrightness(50);
  pixels_low.begin(); // This initializes the NeoPixel library.
  pixels_low.setBrightness(50);
  //////////////////////////////////////////////////////////////////////////////네오픽셀
  while (!Serial) {};
  MP3.begin(mp3_sws);      // Beginning the MP3 player requires a serial port (either hardware or software!!!)
  Serial.println("MP3 Breakout - Example1 Serial Control");
  Serial.println();
  MP3.setVolume(10);
  MP3.playTrackNumber(0);
  ////////////////////////////////////////////////////////////////////////mp3모듈
  myservo.attach(PUMPPIN);
  ////////////////////////////////////////////////////////////////////////펌프

}

void loop() {
  long duration1, distance1;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig1, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig1, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig1, LOW);        // Trig 핀 Low

  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 * 170 / 1000;

  Serial.print("거리1: ");
  Serial.print(distance1); // 거리를 시리얼 모니터에 출력
  Serial.println("mm");
  delay(300);

  long duration2, distance2;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig2, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig2, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig2, LOW);        // Trig 핀 Low

  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2 * 170 / 1000;

  Serial.print("거리2: ");
  Serial.print(distance2); // 거리를 시리얼 모니터에 출력
  Serial.println("mm");
  delay(300);

  long duration3, distance3;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig3, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig3, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig3, LOW);        // Trig 핀 Low

  duration3 = pulseIn(echo3, HIGH);
  distance3 = duration3 * 170 / 1000;

  Serial.print("거리3: ");
  Serial.print(distance3); // 거리를 시리얼 모니터에 출력
  Serial.println("mm");
  delay(300);


  long duration4, distance4;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig4, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig4, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig4, LOW);        // Trig 핀 Low

  duration4 = pulseIn(echo4, HIGH);
  distance4 = duration4 * 170 / 1000;

  Serial.print("거리4: ");
  Serial.print(distance4); // 거리를 시리얼 모니터에 출력
  Serial.println("mm");
  delay(300);

  long duration_top, distance_top;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig_top, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig_top, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig_top, LOW);        // Trig 핀 Low

  duration_top = pulseIn(echo_top, HIGH);
  distance_top = duration_top * 170 / 1000;

  Serial.print("거리_top : ");
  Serial.print(distance_top); // 거리를 시리얼 모니터에 출력
  Serial.println("mm");
  delay(300);

  long duration_mot, distance_mot;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig_mot, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig_mot, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig_mot, LOW);        // Trig 핀 Low

  duration_mot = pulseIn(echo_mot, HIGH);
  distance_mot = duration_mot * 170 / 1000;

  Serial.print("거리_mot: ");
  Serial.print(distance_mot); // 거리를 시리얼 모니터에 출력
  Serial.println("mm");
  delay(100);
  ///////////////////////////////////////사용자 가까이 왔는지 보는 초음파센서

  if (distance1 < 100) //컵을 올려놨을 때
  {
    if (distance4 <= 100) //초음파센서 4번 높이에 컵 걸렸을때
    {
      if (distance_top > 100) //상판 초음파센서와 수면까지 거리가 100보다 클때 작동되게
      {
        myservo.write(180);  //반시계 펌프 작동
        //////////////////////////////////////////////////////////////////////펌프 작동
        for (int i = 0; i < NUMPIXELS_high; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          //pixels.setPixelColor(i, pixels.Color(127,229,229));     //(65, 246, 228));
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(200);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위쪽 led 작동
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == STATUS_STOP) && (autoplay == true))
        {
          MP3.getSongName();
          MP3.playNext();
          delay(100);           // It takes a moment for the device to know the next song name
          /*Serial.print("Playing: ");
            Serial.write(MP3.songName, 8);
            Serial.println();*/
        }
      }
      //////////////////////////////////////////////////////////////////////mp3나오기
      else if (distance_top <= 100) //상판 초음파센서와 수면까지 거리가 100보다 작거나 같을때 작동 멈추게
      {
        myservo.write(90);  //Stop
        //////////////////////////////////////////////////////////////////////펌프 종료
        for (int i = 0; i < NUMPIXELS_high; i++) {
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(0);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위LED 끄기
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == 1) && (autoplay == 1))
        {
          MP3.getSongName();
          MP3.stopPlaying();
          //delay(100);
        }
        ////////////////////////////////////////////////////////////////////////mp3 종료
      }
    }
    else if (distance4 > 100 && distance3 <= 100)
    {
      if (distance_top > 175) ////상판 초음파센서와 수면까지 거리가 175보다 클때 작동되게
      {
        myservo.write(180);
        //////////////////////////////////////////////////////////////////////펌프 작동
        for (int i = 0; i < NUMPIXELS_high; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          //pixels.setPixelColor(i, pixels.Color(127,229,229));     //(65, 246, 228));
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(200);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위쪽 led 작동
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == STATUS_STOP) && (autoplay == true))
        {
          MP3.getSongName();
          MP3.playNext();
          delay(100);           // It takes a moment for the device to know the next song name
          /*Serial.print("Playing: ");
            Serial.write(MP3.songName, 8);
            Serial.println();*/
        }
        //////////////////////////////////////////////////////////////////////mp3나오기
      }
      else if (distance_top <= 175) //상판 초음파센서와 수면까지 거리가 175보다 작거나 같을때 작동 멈추게
      {
        myservo.write(90);
        //////////////////////////////////////////////////////////////////////펌프 종료
        for (int i = 0; i < NUMPIXELS_high; i++) {
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(0);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위LED 끄기
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == 1) && (autoplay == 1))
        {
          MP3.getSongName();
          MP3.stopPlaying();
          delay(100);
        }
        ////////////////////////////////////////////////////////////////////////mp3 종료
      }
    }
    else if (distance4 > 100 && distance3 > 100 && distance2 <= 100)
    {
      if (distance_top > 200) ////상판 초음파센서와 수면까지 거리가 200보다 클때 작동되게
      {
        myservo.write(180);
        //////////////////////////////////////////////////////////////////////펌프 작동
        for (int i = 0; i < NUMPIXELS_high; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          //pixels.setPixelColor(i, pixels.Color(127,229,229));     //(65, 246, 228));
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(200);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위쪽 led 작동
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == STATUS_STOP) && (autoplay == true))
        {
          MP3.getSongName();
          MP3.playNext();
          delay(100);           // It takes a moment for the device to know the next song name
          /*Serial.print("Playing: ");
            Serial.write(MP3.songName, 8);
            Serial.println();*/
        }
        //////////////////////////////////////////////////////////////////////mp3나오기
      }
      else if (distance_top <= 200) //상판 초음파센서와 수면까지 거리가 200보다 작거나 같을때 작동 멈추게
      {
        myservo.write(90);
        //////////////////////////////////////////////////////////////////////펌프 종료
        for (int i = 0; i < NUMPIXELS_high; i++) {
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(0);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위LED 끄기
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == 1) && (autoplay == 1))
        {
          MP3.getSongName();
          MP3.stopPlaying();
          delay(100);
        }
        ////////////////////////////////////////////////////////////////////////mp3 종료
      }
    }
    else  // 제일 작은 컵 검사
    {
      if (distance_top > 220) ////상판 초음파센서와 수면까지 거리가 220보다 클때 작동되게
      {
        myservo.write(180);
        //////////////////////////////////////////////////////////////////////펌프 작동
        for (int i = 0; i < NUMPIXELS_high; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          //pixels.setPixelColor(i, pixels.Color(127,229,229));     //(65, 246, 228));
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(200);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위쪽 led 작동
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == STATUS_STOP) && (autoplay == true))
        {
          MP3.getSongName();
          MP3.playNext();
          delay(100);           // It takes a moment for the device to know the next song name
          /*Serial.print("Playing: ");
            Serial.write(MP3.songName, 8);
            Serial.println();*/
        }
        //////////////////////////////////////////////////////////////////////mp3나오기
      }
      else if (distance_top <= 220) //상판 초음파센서와 수면까지 거리가 220보다 작거나 같을때 작동 멈추게
      {
        myservo.write(90);
        //////////////////////////////////////////////////////////////////////펌프 종료
        for (int i = 0; i < NUMPIXELS_high; i++) {
          pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
          pixels_high.setBrightness(0);
          pixels_high.show(); // This sends the updated pixel color to the hardware.
        }
        ////////////////////////////////////////////////////////////////////////위LED 끄기
        uint8_t status = MP3.getPlayStatus();
        uint8_t playStatus = MP3.getPlayStatus();

        if ((playStatus == 1) && (autoplay == 1))
        {
          MP3.getSongName();
          MP3.stopPlaying();
          delay(100);
        }
        ////////////////////////////////////////////////////////////////////////mp3 종료
      }
    }
  }
  else if (distance1 >= 100)
  {
    for (int i = 0; i < NUMPIXELS_high; i++) {
      pixels_high.setPixelColor(i, pixels_high.Color(127, 229, 229));
      pixels_high.setBrightness(0);
      pixels_high.show(); // This sends the updated pixel color to the hardware.
    }
  }
  //위쪽 led 끄는거
  ////////////////////////////////물 나올때 노래 나오게 하기
  for (int i = 0; i < NUMPIXELS_low; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //pixels.setPixelColor(i, pixels.Color(127,229,229));     //(65, 246, 228));
    if (distance_mot < 300)
    {
      pixels_low.setPixelColor(i, pixels_low.Color(127, 229, 229));
      pixels_low.setBrightness(200);
      pixels_low.show(); // This sends the updated pixel color to the hardware.
    }
    else if (distance_mot >= 300)
    {
      pixels_low.setPixelColor(i, pixels_low.Color(127, 229, 229));
      pixels_low.setBrightness(0);
      pixels_low.show(); // This sends the updated pixel color to the hardware.
    }
  }
}
