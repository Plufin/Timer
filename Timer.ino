#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
	Serial.begin(115200);

	if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		while (1) {
		  delay(10);
		}
	}
	Serial.println("MPU6050 Found!");

	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);

	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

	delay(100);
}

void loop() {

	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	/* Print out the values */
//	Serial.print("Acceleration X: ");
Serial.print("X:");	Serial.print(a.acceleration.x);	Serial.print(",");
Serial.print("Y:");	Serial.print(a.acceleration.y); Serial.print(",");
Serial.print("Z:");	Serial.print(a.acceleration.z);
	//Serial.print(" m/s^2");

Serial.print(",");
Serial.print("Gyro_X:");  Serial.print(g.gyro.x); Serial.print(",");
Serial.print("Gyro_Y:");	Serial.print(g.gyro.y); Serial.print(",");
Serial.print("Gyro_Z:"); Serial.print(g.gyro.z); Serial.print(",");
	//Serial.println(" rad/s");

	Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.print(",");
	//Serial.println(" degC");

	Serial.println("");
	delay(100);
}