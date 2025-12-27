# Christmas 2025 Project
<p align = "center"><img src = "images/main.jpg"></p>
## Background

In the Philippines :philippines:, Christmas is usually the most awaited and favorite season of all time. Starting from September, the ambience transitions into a much jollier and brighter side with occassional Mariah Carey's hit _All I Want for Christmas Is You_ playing on the street. This light and invigorating spirit is what sets Filipino culture apart after having been in Europe for two years. Now, being able to return home with all the brand new and more reinforced knowledge I gathered from my master's studies, I encouraged my creativity to embark on a project that utilized the available electronics materials I had at hand. I intentionally finished this project right before Christmas time so I could run  it while we listened to Christmas songs on TV&ndash;which was a really exciting way to celebrate this season!

To start off, this project consisted of two parts: the _**screen**_ and the _**lights**_. Each part has its own microcontroller unit (MCU)&ndash;the **_ATmega328p_**&ndash;mounted on an Arduino UNO board. 

The 8x8 matrix tube **screen** flashes the `MERRY XMAS!` message moving from right to left. On the other hand, the **lights** part consists of four LEDS (red, green, yellow and blue), which have five different lighting configurations with the last one being the combination of the first four in a consecutive manner. More details about them are explained in the later sections.

## Materials
These are the materials I used for each part:

**Screen**
- **1088BS** 8x8 matrix tube screen (Documentation can be found in this [link](https://www.topliteusa.com/uploadfile/2014/0825/A-1088BS.pdf). Similar matrix can be used but _always refer to its datasheet_ because I did not use any driver to run it, and the pins have to be connected accordingly to flash what you intend to show.)
- Eight **1k&ohm;-resistors**
- One **tactile switch**
- **Arduino UNO** development board with **ATmega328p** microncontroller
- Wires
- _Optional:_ One **9V battery**

**Lights**
- Four **LEDs** (can be any color, but I used red, green, yellow and blue)
- Four **1k&ohm;-resistors**
- One **tactile switch**
- **Arduino UNO** development board with **ATmega328p** microncontroller
- Wires
- _Optional:_ One **9V battery**

## Schematic

### Screen
<p align = "center"><img src = "images/screen.png"></p>
<p align = "center"><b>Figure 1.</b> Schematic diagram of the wire connections of the 1088BS matrix to the Arduino UNO development board controlled by a switch in pull-up setting. I did not find any matrix design in Tinkercad so I just put its detailed schematics as an array of LEDs. This design was created from this website: <a href = "https://www.circuit-diagram.org/editor/">https://www.circuit-diagram.org/editor/</a>.</p>

The general circuit design for the **screen** part is provided above. The matrix represented as an array of LEDs has also been documented as such in its datasheet [here](https://www.topliteusa.com/uploadfile/2014/0825/A-1088BS.pdf). It is important to note that the matrix does not have its own internal resistors as given in **Figure 1**. This is the reason that there are eight 1k&ohm;-resistors included in the materials. There is a switch included which turns the screen _ON_ and _OFF_. However, this is just the circuit connections, and its working function is defined by the Arduino code uploaded to the microcontroller.

### Lights
<p align = "center"><img src = "images/lights.png"></p>
<p align = "center"><b>Figure 2.</b> Breadboard connections for the four-LED system controlled by a switch in pull-up configuration. Schematics created from <a href = "https://www.tinkercad.com/">https://www.tinkercad.com/</a> using the circuits option.</p>

For this part, there are LED light array configuration as follows, controlled by pressin a button in a chronological order:
- **Case 1:** Lights fade in then fade out
- **Case 2:** Lights blink
- **Case 3:** Light "pulse" going from one LED to the next. Goes to the first LED after it reaches the last LED.
- **Case 4:** Two sets of LEDs alternate blinking
- **Case 5:** Cases 1-4

Once all the cases have been performed, the LEDs just turn off. Pressing the button reinitiates the cases.

## Codes
Before uploading the codes into the microcontrollers, make sure to install the **Arduino IDE**. Set the board to `Arduino UNO` (can be downloaded [here](https://www.arduino.cc/en/software/)) and make sure that there is a port connection. Once initialized, the following codes must be uploaded to two separate Arduino development boards:
- **Screen:** [`screen.ino`](https://github.com/machinedeck/Christmas-2025-Project/blob/main/screen/screen.ino)
- **Lights:** [`lights.ino`](https://github.com/machinedeck/Christmas-2025-Project/blob/main/lights/lights.ino)

For [`screen.ino`](https://github.com/machinedeck/Christmas-2025-Project/blob/main/screen/screen.ino), I had to manually design the array for the `MERRY XMAS!` message in Excel, then convert them into a `.CSV` file to copy the array into Arduino code. All these information can be found in the following files: `screen_data.txt`, `screen_data.csv`, and `screen_data.xlsx`. Moreover, upon researching, it could be impossible to, say, individually control an array element of the matrix at a time. This is where I struggled the most because I initialized the matrix to a some array of 0's and 1's, but I ended up having one column all turned _ON_ when only a few has to be such. For this, **I had to resort to ChatGPT to seek help**. **I am highlighting this point to go back and understand this matter later on**, I just needed to finish it before Christmas.

For [`lights.ino`](https://github.com/machinedeck/Christmas-2025-Project/blob/main/lights/lights.ino), I was mostly inspired by the lighting mechanism of the Christmas lights displayed outside my neighbor's house. That's where I got the idea of changing configurations, but allows the user to change it at will with a switch.

For both codes, I used switches to control their initialization, termination and configurations by utilizing the [`attachInterrupt()`](https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/). This interrupt function is initialized in the setup.

## Comments
I noticed that for the **lights** part, I noticed some misalignments with the button press and the LED light configuration. I have not quantified this disparity nor possible delay but there could be some synchronization error, or the with the code itself. I noticed this especially in **Case 5**, where it is supposed to start from **Case 1**. However, there were instances where it just turned _OFF_ or does not start with **Case 1**. I suspect that it might have to do with the code because I once ran the script printing a defined "counter" value, and there was a little problem.

Furthermore, I experienced some memory problem during the course of code development. Before this, I was not able to control the lights independently, which I resolved by using the [`millis()`](https://docs.arduino.cc/language-reference/en/functions/time/millis/) function to avoid blocking code with [`delay()`](https://docs.arduino.cc/language-reference/en/functions/time/delay/). Now, with memory, I have realized how efficient programming is important to expedite process and save storage. For this reason I launched this [repository](https://github.com/machinedeck/Firmware-Programming-1) to learn about efficient embedded programming using registers in C++.

## KiCAD
I also tried to make a KiCAD design, which is provided in this [folder](https://github.com/machinedeck/Christmas-2025-Project/tree/main/xmas).

## Disclaimer
I used ChatGPT mainly to debug my codes and/or seek help regarding their functionalities.
