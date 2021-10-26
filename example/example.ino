#include "PushButtonMulticlickConfiguration.h"

Runner runner;

void setup()
{
  runner.init();
  runner.setConfig(new PushButtonMulticlickConfiguration());
}

void loop()
{
  runner.loop();
}
