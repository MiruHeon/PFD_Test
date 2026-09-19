import processing.serial.*;

Serial port;

float roll = 0;
float pitch = 0;

void setup() {
  size(800, 600);

  port = new Serial(this, "COM3", 115200);
  port.bufferUntil('\n');
}

void draw() {
  background(0);

  translate(width / 2, height / 2);

  pushMatrix();

  rotate(radians(-roll));
  translate(0, pitch * 5);

  noStroke();

  fill(80, 150, 220);
  rect(-500, -500, 1000, 500);

  fill(130, 90, 50);
  rect(-500, 0, 1000, 500);

  stroke(255);
  strokeWeight(3);
  line(-500, 0, 500, 0);

  popMatrix();

  stroke(255, 220, 0);
  strokeWeight(5);

  line(-100, 0, -20, 0);
  line(20, 0, 100, 0);
  line(-20, 0, 0, 15);
  line(20, 0, 0, 15);
}

void serialEvent(Serial p) {
  String data = p.readStringUntil('\n');

  if (data == null) return;

  data = trim(data);

  if (!data.startsWith("Orientation:")) return;

  data = data.replace("Orientation:", "");

  String[] values = splitTokens(data);

  if (values.length >= 2) {
    roll = float(values[0]);
    pitch = float(values[1]);
  }
}
