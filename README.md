# arduino-tvkey

### This is my holiday project aimed to restore lost tv child protection key.

So, I have old Sharp-TV with child protection key set, which was succesfully and fully forgotten. I tried to restore it by googling, typing common keys, but all without success. After all I had only two options: pay to tv-repair workshop or try to find key with arduino.

Once I bought 39-items kit with various sensors for adruino, which contains IR-receiver and IR-sender. My idea was to read ir-commands from remote and then send all possible combinations to tv until I'll find my forgotten key. I was going to use web-camera and make shot after each try, so I'll easily find correct code by analyzing these shots.

First, and most difficult problem was with reading codes. My IR-sensors (I suppose it is KY-202) returns nearly random values. I'm not great specialist in electronics, but I've installed so-called "pull-up resistor" and it gives me a little improvement in quality. 
![ir_receiver](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/receiver.jpg)

I analyzed code of IRRemote arduino library and found that sharp remote should have some valid values, so I used them as anchors to round values from my noisy receiver:

```
unsigned long valid_codes[6] = {15, 245, 1805, 795, 600000, 3000};
```

All other things was quite simple. I installed my sharp-TV under my table, installed web camera and ir-sender. I wrote simple python script which sends remote commands to TV and makes shots with web-camera. My first version of this script took about 30 seconds to test one secrect key, the second one was need only 15 seconds.

![ir sender](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/sender.jpg)
![whole installation](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/Installation.jpg)
![sender installed](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/installed_sender.jpg)
![web camera](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/web_camera.jpg)

After night I found my code :) It was 3001 and I have no idea why I set this number. 
It was quite easy to find image with correct code - the first image below for incorrect code, the second one is for correct. They are completely different:
![ir_receiver](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/3000.jpg)
![ir_receiver](https://raw.githubusercontent.com/mdmitr/arduino-tvkey/master/results/3001.jpg)



