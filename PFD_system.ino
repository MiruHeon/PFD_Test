#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"

MPU6050 mpu;
bool dmpReady = false;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];
Quaternion q;
VectorFloat gravity;
float ypr[3];

void setup() {
    Wire.begin();
    Wire.setClock(400000);
    Serial.begin(115200);

    mpu.initialize();
    if (mpu.dmpInitialize() == 0) {
        mpu.setDMPEnabled(true);
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    }
}

void loop() {
    if (!dmpReady) return;
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        Serial.print("Orientation: ");
        Serial.print(ypr[2] * 180/M_PI); // Roll
        Serial.print(" ");
        Serial.println(ypr[1] * 180/M_PI); // Pitch
        delay(10);
    }
}
