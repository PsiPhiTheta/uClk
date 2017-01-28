// <editor-fold defaultstate="collapsed" desc="0. INFORMATION & NOTES">

	/////////////////////////
	// Lab assessment ME II	/
	// Name: Thomas Hollis	/
	// Student ID: 9563426  /
	// Mini-Project 		/
	/////////////////////////

	//Port A: Analogue inputs from the rotary potentiometer (RA0), the LM335Z temperature sensor (RA1) and the Light Dependent Resistor (RA2). Digital output to control the LED transistor Q3 (RA4). 5V closed, 0V open. 
	//Port B: Push-button PB2 digital input (RB0).
	//Port C: Toggle switch digital inputs (RC2, RC3, RC4 and RC5). Least significant.
	//Port F: Digital outputs to control 8 LEDs and 7seg displays (RF0 ? RF7). Write 0V to illuminate. 
	//Port H: Digital outputs to control 7-segment transistors Q1 and Q2 (RH0 and RH1). 0V closed, 5V open. Toggle switch digital inputs (RH4, RH5, RH6 and RH7). Most significant.
	//Port J: Push-button PB1 digital input (RJ5). Digital output for controlling the sounder (RJ6).

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="1. PREPROCESSOR DIRECTIVES">
    #include "adc.h"                  //Included for ADC functions, remember to enable File/Project Properties/Linker/Link in periferal
    #include "delays.h"               //Included for delay function
    #include "math.h"                 //Included for mathematical operations
    #include "pconfig.h"              //Included for PIC configuration file
    #include "stdio.h"                //Included for IO functions
    #include "time.h"                 //Included for calendar functions
    #include "timers.h"               //Included for Timer Functions
    #include "xc_config_settings.h"   //Included for custom configuration bit settings
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="2. DEFINITIONS">
    //#define PI 3.1415926
	//#define E 2.71828182846
	//#define E0 0.00000000000885
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="3. FUNCTION PROTOTYPES">
    //3.1 MAIN FUNCTIONS
void test_routine(void);    //Turns LEDs on and off (for debugging), only displayed if the while loop is broken out of

    //3.2 CONFIGURATION FUNCTIONS
void config_IO(void);                    //Sets up default IO configuration for project
void config_Timer1(void);                //Sets up Timer1 configuration bits for project
void config_Global_Interrupts(void);     //Sets up Global Interrupt configuration bits for project
void config_ADC_pot(void);               //Sets up ADC configuration bits for potentiometer 
void config_ADC_LDR(void);               //Sets up ADC configuration bits for LDR
void config_ADC_TEMP(void);              //Sets up ADC configuration bits for temperature probe

    //3.3 IO FUNCTIONS
void display_on_U1(unsigned char LSV);              //Displays Least Significant Value (LSV) on display U1
void display_on_U2(unsigned char MSV);              //Displays Most Significant Value (MSV) on display U1
void display_off_SSDs(void);                        //Turns off both Seven Segment Displays (SSD)
void display_on_LEDs(unsigned char LED_val);        //Displays any value (val) on LEDs
void display_off_LEDs(void);                        //Turns off LEDs
unsigned char PB1_pressed(void);                    //Returns 1 (true) if PB1 is pressed, else returns 0 (false)
unsigned char PB2_pressed(void);                    //Returns 1 (true) if PB2 is pressed, else returns 0 (false)
unsigned char get_SWall_val(void);                  //Returns value read from all the switches
unsigned int get_ADC_val(void);                     //Returns value read from ADC
void play_alarm(void);                              //Plays the song Wake Up Boo by The Boo Radleys or plays a simple alarm

    //3.4 MUSIC FUNCTIONS
void F6(void);  //Plays note F6
void D6(void);  //Plays note D6
void C6(void);  //Plays note C6
void B5b(void); //Plays note B5b
void A5(void);  //Plays note A5
void G5(void);  //Plays note G5
void F5(void);  //Plays note F5
void D5(void);  //Plays note D5
void C5(void);  //Plays note C5
void A4(void);  //Plays note A4

    //3.5 ISR FUNCTIONS
void interrupt ISR(void);           //Acknowledges the interrupt flag, resets it to low, calls main TMR1 ISR function
void TMR1_ISR(void);                //Main ISR function that calls all the other functions in order to make the clock work, commented within the function.
void set_time(void);                //Sets the time and date for the current time
void set_alarm(void);               //Sets the time and date for the alarm time
void enable_auto_LDRalarm(void);    //Enables automatic light triggered alarm
void enable_auto_TEMPalarm(void);   //Enables automatic heat triggered alarm
void enable_stopwatch(void);        //Enables basic stopwatch function

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="4. MAIN">
unsigned char ssd_symbols[] = {132, 245, 76, 100, 53, 38, 6, 244, 4, 36, 20, 7, 142, 132, 14, 30};      //Array used to convert values from binary to SSD form (unsigned char used as values between 0-255)
unsigned char current_time[6] = {0, 0, 0, 14, 12, 16};                                                  //Array used to contain current time in s,min,hrs,days,months,years (unsigned char used as values between 0-255)
unsigned char current_alarm[6] = {0, 0, 0, 0, 0, 0};                                                    //Array used to contain alarm time in s,min,hrs,days,months,years (unsigned char used as values between 0-255)

unsigned char SWall_val;    //Variable used to store the value of all the switches (unsigned char used as values between 0-255)
unsigned char SW7_val;      //Variable used to store the value of the most significant switch (7) (unsigned char used as values between 0-255)
unsigned char SW6_val;      //Variable used to store the value of the second most significant switch (6) (unsigned char used as values between 0-255)
unsigned char SW5_val;      //Variable used to store the value of the third most significant switch (5) (unsigned char used as values between 0-255)
unsigned char SW4_val;      //Variable used to store the value of the fourth most significant switch (4) (unsigned char used as values between 0-255)
unsigned char SW3_val;      //Variable used to store the value of the fourth least significant switch (3) (unsigned char used as values between 0-255)
unsigned char SW2_val;      //Variable used to store the value of the third least significant switch (2) (unsigned char used as values between 0-255)
unsigned char SW1_val;      //Variable used to store the value of the second least significant switch (1) (unsigned char used as values between 0-255)
unsigned char SW0_val;      //Variable used to store the value of the first least significant switch (0) (unsigned char used as values between 0-255)

unsigned char MSV;          //Variable used to store most significant value to be displayed (unsigned char used as values between 0-255)
unsigned char LSV;          //Variable used to store most significant value to be displayed (unsigned char used as values between 0-255)

int unit_selector;          //Variable used to select the unit of time to display (int chosen as negative values are used)
unsigned char alarm_type;   //Variable used to indicate whether or not the alarm type is simple or complex

unsigned int unit_counter = 0;              //Variable used to count up to two seconds for displaying each unit sequentially (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int sec_counter = 0;               //Variable used to count once each second elapsed since system was turned on (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned char display_counter = 0;          //Variable used to count up to 3, in order to determine which display is used (unsigned char chosen as negative count not possible and values < 255 are needed)
unsigned int set_time_counter = 0;          //Variable used to check once a second if the time should set or not (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int set_alarm_counter = 0;         //Variable used to check once a second if the alarm should be set or not (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int man_alarm_counter = 0;         //Variable used to check once a second if the manual alarm should be activated (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int auto_LDRalarm_counter = 0;     //Variable used to check once a second if the auto LDR alarm should be activated (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int auto_TEMPalarm_counter = 0;    //Variable used to check once a second if the auto temperature alarm should be activated (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int alarm_type_counter = 0;        //Variable used to check once a second if the preferred alarm type is simple or complex (unsigned int chosen as negative count not possible and values > 255 are needed)
unsigned int stopwatch_counter = 0;         //Variable used to check once a second if the stopwatch feature should be activated (unsigned int chosen as negative count not possible and values > 255 are needed)

void main(void) //Configures IO, timer1, global interrupts and runs test routine if ISR loop broken out of (for debugging only)
{
    config_IO();
    config_Timer1();
    config_Global_Interrupts();
        
    while(1); //Loops forever
    
    test_routine(); //Will display if while loop is broken out of
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="5. FUNCTIONS">
    //5.1 MAIN FUNCTIONS
void test_routine(void)
{
    LATF = 0x00; //Turns all LEDs off
    Delay10KTCYx(250); //Delays for 1s 
    LATF = 0xFF; //Turns all LEDs on
    Delay10KTCYx(250); //Delays 1s 
    LATF = 0x00; //Turns all LEDs off
}

    //5.2 CONFIGURATION FUNCTIONS
void config_IO(void) 
{ 
    ADCON1 = 0b00001111;    //Configures ADCON bits for A/D
    TRISC = 0b11111111;     //Configures switch bank as inputs
    TRISJ = 0b10111111;     //Configures Piezo sounder as output
    display_off_LEDs();     //Configures and turns off LEDs
    display_off_SSDs();     //Configures and turns off SSDs
}
void config_Global_Interrupts(void) 
{
    INTCON = 0xC0; //global interrupts enabled
}
void config_Timer1(void)
{
    OpenTimer1 (TIMER_INT_ON & T1_16BIT_RW & T1_SOURCE_INT & T1_PS_1_8 & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF); //Turns on timer interrupts, 16 bit mode, Prescaler = 8
    WriteTimer1(63974); //Sets the timer value to be 1/400th of a second
}
void config_ADC_pot(void)
{
    OpenADC(ADC_FOSC_16 & ADC_RIGHT_JUST & ADC_0_TAD, ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0x0E); //Configuration: Oscillator frequency = 16, right justified, Channel 0, Interrupts Off, Vref+=VFF, Vref-=VSS
}
void config_ADC_LDR(void)
{
    OpenADC(ADC_FOSC_16 & ADC_RIGHT_JUST & ADC_0_TAD, ADC_CH2 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0x0E); //Configuration: Oscillator frequency = 16, right justified, Channel 2, Interrupts Off, Vref+=VFF, Vref-=VSS
}
void config_ADC_TEMP(void)
{
    OpenADC(ADC_FOSC_16 & ADC_RIGHT_JUST & ADC_0_TAD, ADC_CH1 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0x0E); //Configuration: Oscillator frequency = 16, right justified, Channel 2, Interrupts Off, Vref+=VFF, Vref-=VSS
}

    //5.3 IO FUNCTIONS
void display_on_U1(unsigned char LSV)
{
    TRISH = 0b11111110;        //Sets PortH as input, except pin 0 as output
    LATH = 0b11111110;         //Writes 0 to pin 0, turns on U1 transistor 
    TRISF = 0b00000000;        //Sets PortF as output
    LATF = ssd_symbols[LSV];   //Writes any value in SSD form to LatF
}
void display_on_U2(unsigned char MSV)
{
    TRISH = 0b1111101;        //Sets PortH as input, except pin 1 as output
    LATH = 0b11111101;        //Writes 0 to pin 1, turns on U2 transistor 
    TRISF = 0b00000000;       //Sets PortF as output
    LATF = ssd_symbols[MSV];  //Writes any value in SSD form to LatF 
}
void display_off_SSDs(void)
{
    LATH = 0b11111111; //Turns off U1 and U2 transistors
}
void display_on_LEDs(unsigned char LED_val)
{
    TRISA = 0b11101111;   //Sets PortA as input, except pin 4 as output
    LATA = 0b11111111;    //Writes 1 to pin 4, turns on LED transistor
    TRISF = 0b00000000;   //Sets PortF as output
    LATF = LED_val;       //Writes any value in binary to LATF
}
void display_off_LEDs(void)
{
    LATA = 0x00; //Turns off LED transistor
}
unsigned char PB1_pressed(void)
{
   return (!PORTJbits.RJ5); 
}
unsigned char PB2_pressed(void)
{
   return (!PORTBbits.RB0); 
}
unsigned char get_SWall_val(void)
{
    unsigned char SW1, SW2, SW12;   //Declares SW1, SW2 and SW12 variables
    TRISC=0xFF;                     //Sets PortC as input
    TRISH=0xFF;                     //Sets PortH as input
    SW1 = PORTC >> 2;               //Right shifts value on PortC by 2 to the right
    SW1 = SW1 & 0b00001111;         //Clears 4 most significant bits of SW1
    SW2 = PORTH & 0b11110000;       //Clears 4 least significant bits of SW2
    SW12 = SW1 | SW2;               //Combines SW1 with SW2 to form SW12
    return SW12;                    //Returns the value SW12 read from the switch bank
}
unsigned int get_ADC_val(void)
{
    ConvertADC(); //Converts value in ADC
    while(BusyADC()); //Waits for ADC to finish conversion
    return ReadADC(); //Returns the converted value from ADC
}
void play_alarm(void)
{
    if (alarm_type == 0) //Plays basic alarm (17s)
    {
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
        
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        F6();
        Delay10KTCYx(52);
        
        Delay10KTCYx(52);
        Delay10KTCYx(52);
    }
    else //plays complex alarm (17s)
    {
        display_on_LEDs(255);
        F6();
        display_off_LEDs();
        F6();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        A5();
        display_on_LEDs(255);
        A5();
        display_off_LEDs();
        C6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        C6();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        C5();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        F5();
        display_on_LEDs(255);
        F5();
        display_off_LEDs();
        G5();
        display_on_LEDs(255);
        A5();
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        B5b();
        display_off_LEDs();
        A5();
        display_on_LEDs(255);
        G5();
        display_off_LEDs();
        A5();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        D5();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        C5();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        A4();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        F5();
        display_on_LEDs(255);
        F5();
        display_off_LEDs();
        F6();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        A5();
        display_on_LEDs(255);
        A5();
        display_off_LEDs();
        C6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        C6();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        C5();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        F5();
        display_on_LEDs(255);
        F5();
        display_off_LEDs();
        G5();
        display_on_LEDs(255);
        A5();
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        F5();
        display_on_LEDs(255);
        A5();
        display_off_LEDs();
        C6();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        D6();
        display_off_LEDs();
        D6();
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        Delay10KTCYx(52);
        display_on_LEDs(255);
        Delay10KTCYx(52);
        display_off_LEDs();
        Delay10KTCYx(52);
    }
}

    //5.4 MUSIC FUNCTIONS
void F6(void)
{
    for(int i = 0; i < 143; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(18); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(18);
    }
}
void D6(void)
{
    for(int i = 0; i < 122; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(21); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(21);
    }
}
void C6(void)
{
    for(int i = 0; i < 109; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {    
        LATJ = 0x40;
        Delay100TCYx(24); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(24);
    }
}
void B5b(void)
{
    for(int i = 0; i < 97; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(27); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(27);
    }
}
void A5(void)
{
    for(int i = 0; i < 92; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(28); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(28);
    }
}
void F5(void)
{
    for(int i = 0; i < 73; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(36); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(36);
    }
}
void G5(void)
{
    for(int i = 0; i < 82; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(32); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(32);
    }
}
void D5(void)
{
    for(int i = 0; i < 61; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(43); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(43);
    }
}
void C5(void)
{
    for(int i = 0; i < 55; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(48); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(48);
    }
}
void A4(void)
{
    for(int i = 0; i < 46; i++) //Sets total time for note to be played (crotchet @ 144BPM)
    {
        LATJ = 0x40;
        Delay100TCYx(57); //Sets note frequency
        LATJ = 0x00;
        Delay100TCYx(57);
    }
}

    //5.5 ISR FUNCTIONS
void interrupt ISR(void) 
{
    if(PIR1bits.TMR1IF)         //If interrupt flag is high, executes code below
    { 
        PIR1bits.TMR1IF = 0;    //Turns interrupt flag low as the interrupt has been acknowledged
        TMR1_ISR();             //Calls the main ISR function
    }
}
void TMR1_ISR(void)
{
    WriteTimer1(63974); //Delays by 0.005s so refresh rate is 200Hz
    
    sec_counter++;
    if (sec_counter == 200) //If 1s has elapsed
    {
        current_time[0]++; //Increments seconds every second
        if (current_time[0] > 59) //For when 1min has elapsed
        {   
            current_time[0] = 0; //Resets seconds
            current_time[1]++; //Increments minutes
            if (current_time[1] > 59) //For when 1hr has elapsed
            {
                current_time[1] = 0; //Resets minutes
                current_time[2]++; //Increments hours
                if (current_time[2] > 23) //For when 1day has elapsed
                {
                    current_time[2] = 0; //Resets hours
                    current_time[3]++; //Increments days
                    
                    if (current_time[3] >= 28) //For when 1month might have elapsed
                    {
                        switch (current_time[4]) //Checks month as outcome depends on each month
                        {
                            case 4: //For all the months with 30 days
                            case 6:
                            case 9:
                            case 11:
                            {
                                if (current_time[3] == 31) //For when 1month has elapsed
                                {
                                    current_time[3] = 1; //Resets days
                                    current_time[4]++; //Increments months
                                }
                            }
                            break;
                            
                            case 1: //For all the months with 31 days 
                            case 3:
                            case 5:
                            case 7:
                            case 8:
                            case 10:
                            case 12: 
                            {
                                if (current_time[3] >= 32) //For when 1month has elapsed
                                {
                                    current_time[3] = 1; //Resets days
                                    current_time[4]++; //Increments months
                                }
                            }
                            break;
                            
                            case 2: //For February
                            {
                                if (current_time[5] % 4 == 0) //For when 1month has elapsed
                                {
                                    if (current_time[3] == 30) //For leap years
                                    {
                                        current_time[3] = 1; //Reset days
                                        current_time[4]++; //Increment months
                                    }
                                }
                                else
                                {
                                    if (current_time[3] == 29) //For non-leap years
                                    {
                                        current_time[3] = 1; //Resets days
                                        current_time[4]++; //Increments months
                                    }
                                }
                            }
                            break;
                        }
                        
                        if (current_time[4] > 12) //For when 1yr has elapsed
                        {
                            current_time[4] = 1; //Resets months
                            current_time[5]++; //Increments years
                            
                            if (current_time[5] > 99) //For when 100yrs have elapsed
                            {
                                current_time[5] = 0; //Resets years
                            }
                        }
                    }
                }
            }
        }
        sec_counter = 0;
    }
    
    unit_counter++; 
    if(unit_counter == 400) //If 2s has elapsed
    {
        SW7_val = get_SWall_val() & 0b10000000; //Reads all switches, selects only value of switch 7 and writes to SW7 variable
        if(SW7_val == 0b10000000) //If switch 7 is on, shows years, months, days
        {
            if(unit_selector <= 3) //And if unit selected is less than or equal to 3 (days)
                unit_selector = 6; //Reset unit selected to 6 (years) before counting down
        }
        else    //If switch 7 is off, shows hours, minutes, seconds
        {
            if(unit_selector == 0 || unit_selector > 3) //And if unit selected is 0 (not defined) or larger than 3 (hours) (ie if not hours, mins or seconds)
                unit_selector = 3; //Reset unit selected to 3 (hours) before counting down
        }
        unit_selector--; //Decrements unit selector
        unit_counter = 0; //Resets the unit counter
    }
    
    display_counter++; //Increments the display counter to determine where to display information
    MSV = current_time[unit_selector]/10; //Writes MSV of current time to MSV
    LSV = current_time[unit_selector] - MSV*10; //Writes LSV of current time to LSV
    switch (display_counter) //Displays on 3 different areas: U1, U2 and LEDs via multiplexing
    {
        case 1: //Display on U1
        {
            display_off_LEDs();
            display_on_U1(LSV); //Displays on U1 LSV of unit time selected
            break; //Breaks (ie does not reset the display counter)
        }        
        case 2: //Display on U2
        {
            display_off_LEDs();
            display_on_U2(MSV); //Displays on U2 MSV of unit time selected
            break; //Breaks (ie does not reset the display counter)
        }
        case 3: //Display on LEDs
        {
            display_off_SSDs(); 
            display_on_LEDs((int)pow(2, (unit_selector + 2))); //Displays on LEDs 7 to 2 the current unit being read
            display_counter = 0; //Resets the display counter
        }  
    }
    
    set_time_counter++; //Increments the set time counter to determine whether or not the time should be set
    if (set_time_counter == 200) //Checks each second if the time is to be set
    {
        SW6_val = get_SWall_val() & 0b01000000; //Reads all switches, selects only value of switch 6 and writes to SW6 variable
        if (SW6_val == 0b01000000) //If switch 6 is on, set time function is called
        {
            set_time();
        }
        set_time_counter = 0; //Resets the set time counter
    }
    
    set_alarm_counter++; //Increments the set alarm counter to determine whether or not to set the alarm
    if (set_alarm_counter == 200) //Checks each second if the alarm should be set
    {
        SW5_val = get_SWall_val() & 0b00100000; //Reads all switches, selects only value of switch 5 and writes to SW5 variable
        if (SW5_val == 0b00100000) //If switch 5 is on, calls set alarm function
        {
            set_alarm();
        }
        set_alarm_counter = 0; //Resets the set alarm counter
    }
    
    man_alarm_counter++; //Increments the manual alarm counter to determine whether or not to have manual alarms
    if (man_alarm_counter == 200) //Checks each second if the alarm should be manual or not
    {
        SW4_val = get_SWall_val() & 0b00010000; //Reads all switches, selects only value of switch 4 and writes to SW4 variable
        if (SW4_val == 0b00010000) //If switch 4 is on, enables manual alarm mode
        {
            if ((current_time[0] == current_alarm[0])&&(current_time[1] == current_alarm[1])&&(current_time[2] == current_alarm[2])&&(current_time[3] == current_alarm[3])&&(current_time[4] == current_alarm[4])&&(current_time[5] == current_alarm[5]))
            {
                play_alarm(); //Plays if and only if all the values in the array of current_time[] are equal to those in current_alarm[]
                if (current_time[0] < 43) //If the current time is not going to overflow 
                { 
                    current_time[0] = current_time[0] + 17; //Increment seconds by seconds lost by playing alarm 
                }
                else //If the current time is going to overflow
                {
                    current_time[1]++; //Increment the minutes by one
                    current_time[0] = (current_time[0]  + 17)-60; //Increment the seconds by the seconds lost by playing alarm with overflow
                    
                    if (current_time[1] > 59) //For when 1hr has elapsed
                    {
                        current_time[1] = 0; //Resets minutes
                        current_time[2]++; //Increments hours
                        if (current_time[2] > 23) //For when 1day has elapsed
                        {
                            current_time[2] = 0; //Resets hours
                            current_time[3]++; //Increments days
                    
                            if (current_time[3] >= 28) //For when 1month might have elapsed
                            {
                                switch (current_time[4]) //Checks month as outcome depends on each month
                                {
                                    case 4: //For all the months with 30 days
                                    case 6:
                                    case 9:
                                    case 11:
                                    {
                                    if (current_time[3] == 31) //For when 1month has elapsed
                                        {
                                            current_time[3] = 1; //Resets days
                                            current_time[4]++; //Increments months
                                        }
                                    }
                                    break;
                            
                                    case 1: //For all the months with 31 days 
                                    case 3:
                                    case 5:
                                    case 7:
                                    case 8:
                                    case 10:
                                    case 12: 
                                    {
                                        if (current_time[3] >= 32) //For when 1month has elapsed
                                        {
                                            current_time[3] = 1; //Resets days
                                            current_time[4]++; //Increments months
                                        }
                                    }
                                    break;
                            
                                    case 2: //For February
                                    {
                                        if (current_time[5] % 4 == 0) //For when 1month has elapsed
                                        {
                                            if (current_time[3] == 30) //For leap years
                                            {
                                                current_time[3] = 1; //Reset days
                                                current_time[4]++; //Increment months
                                            }
                                        }
                                        else
                                        {
                                            if (current_time[3] == 29) //For non-leap years
                                            {
                                                current_time[3] = 1; //Resets days
                                                current_time[4]++; //Increments months
                                            }
                                        }
                                    }
                                    break;
                                }
                        
                                if (current_time[4] > 12) //For when 1yr has elapsed
                                {
                                    current_time[4] = 1; //Resets months
                                    current_time[5]++; //Increments years
                            
                                    if (current_time[5] > 99) //For when 100yrs have elapsed
                                    {
                                        current_time[5] = 0; //Resets years
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        man_alarm_counter = 0;
    }
    
    auto_LDRalarm_counter++; //Increments the alarm counter to determine whether or not to check the LDR alarm switch
    if (auto_LDRalarm_counter == 200) //Checks each second if the auto LDR alarm should be enable
    {
        SW3_val = get_SWall_val() & 0b00001000; //Reads all switches, selects only value of switch 3 and writes to SW3 variable
        if (SW3_val == 0b00001000) //If switch 3 is on, enables auto LDR alarm mode
        {
            enable_auto_LDRalarm();
        }
        auto_LDRalarm_counter = 0;//Resets the auto LDR alarm counter
    }
    
    auto_TEMPalarm_counter++; //Increments the thermometer counter to determine whether or not to activate thermometer alarm mode
    if (auto_TEMPalarm_counter == 200) //Checks each second if the thermometer mode should be activated
    {
        SW2_val = get_SWall_val() & 0b00000100; //Reads all switches, selects only value of switch 2 and writes to SW2 variable
        if (SW2_val == 0b00000100) //If switch 2 is on, thermometer alarm mode activated
        {
            enable_auto_TEMPalarm();
        }
        auto_TEMPalarm_counter = 0; //Resets the set alarm counter
    }
    
    alarm_type_counter++; //Increments the alarm type counter to determine whether or not to check if alarm type is simple or complex
    if (alarm_type_counter == 200) //Checks each second if the alarm is simple or complex
    {
        SW1_val = get_SWall_val() & 0b00000010; //Reads all switches, selects only value of switch 1 and writes to SW1 variable
        if (SW1_val == 0b00000010) //If switch 1 is on, complex alarm mode activated
        {
            alarm_type = 1; //Sets alarm type to complex
        }
        else
        {
            alarm_type = 0; //Sets alarm type to simple
        }
        alarm_type_counter = 0; //Resets the set alarm counter
    }
    
    stopwatch_counter++; //Increments the stopwatch counter to determine whether or not to go into stopwatch mode
    if (stopwatch_counter == 200) //Checks each second if the stopwatch should be activated
    {
        SW0_val = get_SWall_val() & 0b00000001; //Reads all switches, selects only value of switch 0 and writes to SW0 variable
        if (SW0_val == 0b00000001) //If switch 0 is on, stopwatch mode activated
        {
            enable_stopwatch();
        }
        stopwatch_counter = 0; //Resets the set alarm counter
    }
}
void set_time(void)
{
    unsigned char pot_val;              //Local variable used to write the value of the potentiometer to a memory location
    int st_PB1_counter = 5;             //Local variable used to control which unit of time is being set
    unsigned char st_MSV = 0;           //Local variable used to display the MSV of pot_val
    unsigned char st_LSV = 0;           //Local variable used to display the LSV of pot_val 
    int st_unit_selector;               //Local variable used to select the unit of time to change
    
    config_ADC_pot();  //Configures the ADC for the potentiometer
    
    while (PB2_pressed() == 0) //Used to exit the set time functionality
    {
        if (PB2_pressed() == 1) //Used to exit the set time functionality
        {
            break; //Leaves the function and returns to the clock main display
        }
        
        switch (st_PB1_counter)
        {
            case 0: //Setting seconds
                pot_val = (get_ADC_val()/17.3); //Scales the ADC to have values of 0-59
                break;
            case 1: //Setting minutes
                pot_val = (get_ADC_val()/17.3); //Scales the ADC to have values of 0-59
                break;
            case 2: //Setting hours
                pot_val = (get_ADC_val()/44); //Scales the ADC to have values of 0-23
                break;
            case 3: //Setting day of month
                switch (current_time[4]) //Depends on month
                {
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        pot_val = (get_ADC_val()/35)+1; //Scales the ADC to have values of 1-30
                        break;
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        pot_val = (get_ADC_val()/34)+1; //Scales the ADC to have values of 1-31
                        break;
                    case 2:
                        if (current_time[5] % 4 == 0)
                        {
                            pot_val = (get_ADC_val()/36)+1; //Scales the ADC to have values of 1-29
                        }
                        else
                        {
                            pot_val = (1+get_ADC_val()/38)+1; //Scales the ADC to have values of 1-28
                        }
                        break;
                }
                break;
            case 4: //Setting month of year
                pot_val = (get_ADC_val()/92)+1; //Scales the ADC to have a max value of 1-12
                break;
            case 5: //Setting year
                pot_val = (get_ADC_val()/10.3); //Scales the ADC to have a max value of 0-99
                break;
        }
        
        display_counter++; //Increments the display counter to determine where to display information
        st_MSV = pot_val/10; //Assigns st_MSV to the MSV of the pot_val
        st_LSV = pot_val - (st_MSV*10); //Assigns st_LSV to the LSV of the pot_val
        switch (display_counter) //Displays on 3 different areas: U1, U2 and LEDs via multiplexing
        {
            case 1: //Display on U1
            {
                display_off_LEDs();
                display_on_U1(st_LSV); //Displays on U1 LSV of unit time selected
                break; //Breaks (ie does not reset the display counter)
            }        
            case 2: //Display on U2
            {
                display_off_LEDs();
                display_on_U2(st_MSV); //Displays on U2 MSV of unit time selected
                break; //Breaks (ie does not reset the display counter)
            }
            case 3: //Display on LEDs
            {
                display_off_SSDs(); 
                display_on_LEDs((int)pow(2, (st_PB1_counter + 2))); //Displays on LEDs 7 to 2 the current unit being written to
                display_counter = 0; //Resets the display counter
            }  
        }
        
        if (PB1_pressed() == 1)
        {
            display_off_LEDs();
            display_off_SSDs();
            current_time[st_PB1_counter] = pot_val;     //Writes current potentiometer value to time
            Delay10KTCYx(60);                           //Debounces PB1
            st_PB1_counter--;                           //Moves the set time function down to the next time unit
            if (st_PB1_counter == -1)
            {
                st_PB1_counter = 5;                     //Resets the st_PB1_counter
            }
        } 
    }
    CloseADC();
}
void set_alarm(void)
{
    unsigned char pot_val;              //Local variable used to write the value of the potentiometer to a memory location
    int sa_PB1_counter = 5;             //Local variable used to control which unit of time is being set for alarm
    unsigned char sa_MSV = 0;           //Local variable used to display the MSV of pot_val
    unsigned char sa_LSV = 0;           //Local variable used to display the LSV of pot_val 
    int sa_unit_selector;               //Local variable used to select the unit of time to change
    
    config_ADC_pot();  //Configures the ADC for the potentiometer
    
    while (PB2_pressed() == 0) //Used to exit the set time functionality
    {
        if (PB2_pressed() == 1) //Used to exit the set time functionality
        {
            break; //Leaves the function and returns to the clock main display
        }
        
        switch (sa_PB1_counter)
        {
            case 0: //Setting seconds
                pot_val = (get_ADC_val()/17.3); //Scales the ADC to have values of 0-59
                break;
            case 1: //Setting minutes
                pot_val = (get_ADC_val()/17.3); //Scales the ADC to have values of 0-59
                break;
            case 2: //Setting hours
                pot_val = (get_ADC_val()/44); //Scales the ADC to have values of 0-23
                break;
            case 3: //Setting day of month
                switch (current_alarm[4]) //Depends on month
                {
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        pot_val = (get_ADC_val()/35)+1; //Scales the ADC to have values of 1-30
                        break;
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        pot_val = (get_ADC_val()/34)+1; //Scales the ADC to have values of 1-31
                        break;
                    case 2:
                        if (current_alarm[5] % 4 == 0)
                        {
                            pot_val = (get_ADC_val()/36)+1; //Scales the ADC to have values of 1-29
                        }
                        else
                        {
                            pot_val = (1+get_ADC_val()/38)+1; //Scales the ADC to have values of 1-28
                        }
                        break;
                }
                break;
            case 4: //Setting month of year
                pot_val = (get_ADC_val()/92)+1; //Scales the ADC to have a max value of 1-12
                break;
            case 5: //Setting year
                pot_val = (get_ADC_val()/10.3); //Scales the ADC to have a max value of 0-99
                break;
        }
        
        display_counter++; //Increments the display counter to determine where to display information
        sa_MSV = pot_val/10; //Assigns st_MSV to the MSV of the pot_val
        sa_LSV = pot_val - (sa_MSV*10); //Assigns st_LSV to the LSV of the pot_val
        switch (display_counter) //Displays on 3 different areas: U1, U2 and LEDs via multiplexing
        {
            case 1: //Display on U1
            {
                display_off_LEDs();
                display_on_U1(sa_LSV); //Displays on U1 LSV of unit time selected
                break; //Breaks (ie does not reset the display counter)
            }        
            case 2: //Display on U2
            {
                display_off_LEDs();
                display_on_U2(sa_MSV); //Displays on U2 MSV of unit time selected
                break; //Breaks (ie does not reset the display counter)
            }
            case 3: //Display on LEDs
            {
                display_off_SSDs(); 
                display_on_LEDs((int)pow(2, (sa_PB1_counter + 2))); //Displays on LEDs 7 to 2 the current unit being written to
                display_counter = 0; //Resets the display counter
            }  
        }
        
        if (PB1_pressed() == 1)
        {
            display_off_LEDs();
            display_off_SSDs();
            current_alarm[sa_PB1_counter] = pot_val;     //Writes current potentiometer value to time
            Delay10KTCYx(60);                           //Debounces PB1
            sa_PB1_counter--;                           //Moves the set time function down to the next time unit
            if (sa_PB1_counter == -1)
            {
                sa_PB1_counter = 5;                     //Resets the st_PB1_counter
            }
        } 
    }
    CloseADC();
}
void enable_auto_LDRalarm(void)
{
    config_ADC_LDR();
    if ((int)(get_ADC_val()/10.3) > 70) //Checks if value of LDR is larger than 70% of max readable value
    {
        play_alarm();
        if (current_time[0] < 43) //If the current time is not going to overflow 
        { 
            current_time[0] = current_time[0] + 17; //Increments seconds by seconds lost by playing alarm 
        }
        else //If the current time is going to overflow
        {
            current_time[1]++; //Increments the minutes by one
            current_time[0] = (current_time[0]  + 17)-60; //Increments the seconds by the seconds lost by playing alarm with overflow
            
            if (current_time[1] > 59) //For when 1hr has elapsed
            {
                current_time[1] = 0; //Resets minutes
                current_time[2]++; //Increments hours
                if (current_time[2] > 23) //For when 1day has elapsed
                {
                    current_time[2] = 0; //Resets hours
                    current_time[3]++; //Increments days
                    
                    if (current_time[3] >= 28) //For when 1month might have elapsed
                    {
                        switch (current_time[4]) //Checks month as outcome depends on each month
                        {
                            case 4: //For all the months with 30 days
                            case 6:
                            case 9:
                            case 11:
                            {
                                if (current_time[3] == 31) //For when 1month has elapsed
                                {
                                    current_time[3] = 1; //Resets days
                                    current_time[4]++; //Increments months
                                }
                            }
                            break;
                            
                            case 1: //For all the months with 31 days 
                            case 3:
                            case 5:
                            case 7:
                            case 8:
                            case 10:
                            case 12: 
                            {
                                if (current_time[3] >= 32) //For when 1month has elapsed
                                {
                                    current_time[3] = 1; //Resets days
                                    current_time[4]++; //Increments months
                                }
                            }
                            break;
                            
                            case 2: //For February
                            {
                                if (current_time[5] % 4 == 0) //For when 1month has elapsed
                                {
                                    if (current_time[3] == 30) //For leap years
                                    {
                                        current_time[3] = 1; //Reset days
                                        current_time[4]++; //Increment months
                                    }
                                }
                                else
                                {
                                    if (current_time[3] == 29) //For non-leap years
                                    {
                                        current_time[3] = 1; //Resets days
                                        current_time[4]++; //Increments months
                                    }
                                }
                            }
                            break;
                        }
                        
                        if (current_time[4] > 12) //For when 1yr has elapsed
                        {
                            current_time[4] = 1; //Resets months
                            current_time[5]++; //Increments years
                            
                            if (current_time[5] > 99) //For when 100yrs have elapsed
                            {
                                current_time[5] = 0; //Resets years
                            }
                        }
                    }
                }
            }
        }    
    }
    CloseADC();
}
void enable_auto_TEMPalarm(void)
{
    config_ADC_TEMP();
    if ((int)((get_ADC_val()/2-343) > 25)) //Checks if value of temperature is larger than 5 degrees Celsius over typical room temperature (20C)
    {
        play_alarm();
        if (current_time[0] < 43) //If the current time is not going to overflow 
        { 
            current_time[0] = current_time[0] + 17; //Increments seconds by seconds lost by playing alarm 
        }
        else //If the current time is going to overflow
        {
            current_time[1]++; //Increments the minutes by one
            current_time[0] = (current_time[0]  + 17)-60; //Increments the seconds by the seconds lost by playing alarm with overflow
            
            if (current_time[1] > 59) //For when 1hr has elapsed
            {
                current_time[1] = 0; //Resets minutes
                current_time[2]++; //Increments hours
                if (current_time[2] > 23) //For when 1day has elapsed
                {
                    current_time[2] = 0; //Resets hours
                    current_time[3]++; //Increments days
                    
                    if (current_time[3] >= 28) //For when 1month might have elapsed
                    {
                        switch (current_time[4]) //Checks month as outcome depends on each month
                        {
                            case 4: //For all the months with 30 days
                            case 6:
                            case 9:
                            case 11:
                            {
                                if (current_time[3] == 31) //For when 1month has elapsed
                                {
                                    current_time[3] = 1; //Resets days
                                    current_time[4]++; //Increments months
                                }
                            }
                            break;
                            
                            case 1: //For all the months with 31 days 
                            case 3:
                            case 5:
                            case 7:
                            case 8:
                            case 10:
                            case 12: 
                            {
                                if (current_time[3] >= 32) //For when 1month has elapsed
                                {
                                    current_time[3] = 1; //Resets days
                                    current_time[4]++; //Increments months
                                }
                            }
                            break;
                            
                            case 2: //For February
                            {
                                if (current_time[5] % 4 == 0) //For when 1month has elapsed
                                {
                                    if (current_time[3] == 30) //For leap years
                                    {
                                        current_time[3] = 1; //Reset days
                                        current_time[4]++; //Increment months
                                    }
                                }
                                else
                                {
                                    if (current_time[3] == 29) //For non-leap years
                                    {
                                        current_time[3] = 1; //Resets days
                                        current_time[4]++; //Increments months
                                    }
                                }
                            }
                            break;
                        }
                        
                        if (current_time[4] > 12) //For when 1yr has elapsed
                        {
                            current_time[4] = 1; //Resets months
                            current_time[5]++; //Increments years
                            
                            if (current_time[5] > 99) //For when 100yrs have elapsed
                            {
                                current_time[5] = 0; //Resets years
                            }
                        }
                    }
                }
            }
        }    
    }
    CloseADC();
}
void enable_stopwatch(void)
{
    unsigned char elapsed_time = 0; //Local variable used to measure elapsed time
    while (PB2_pressed() == 0) //Used to exit the stopwatch functionality
    {
        if (PB2_pressed() == 1) //Used to exit the stopwatch functionality
        {
            break; //Leaves the function and returns to the clock main display
        } 
        if (PB1_pressed() == 1) //Used to start the stopwatch functionality
        {
            Delay10KTCYx(250);
            elapsed_time++;
            while ((PB1_pressed() == 0) && (elapsed_time <= 59)) //Alows either PB1 to stop the count or max count reached
            {
                display_on_LEDs(elapsed_time++);
                Delay10KTCYx(250);  //Debounces PB1 and waits 1s
                elapsed_time++;
            }
            display_on_LEDs(elapsed_time);
            Delay10KTCYx(250);
            Delay10KTCYx(250);
            display_off_LEDs();
            if (current_time[0] < (59-elapsed_time)) //If the current time is not going to overflow 
            { 
                current_time[0] = current_time[0] + elapsed_time; //Increments seconds by seconds lost by using stopwatch
            }
            else //If the current time is going to overflow
            {
                current_time[1]++; //Increments the minutes by one
                current_time[0] = (current_time[0]  + elapsed_time)-60; //Increments the seconds by the seconds lost by using stopwatch with overflow to minutes
            }
            elapsed_time = 0; //Resets the elapsed time counter
        }
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="6. DEBUG STATUS">
   //Debugged	
// </editor-fold>