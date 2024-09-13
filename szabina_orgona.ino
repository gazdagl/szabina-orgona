// Port defines  #########################################################
// nevek a kapcs. rajz alapján, kivéve az egyesített jelek, amiket szétválasztottam és átneveztem
// pin számokat majd átírjuk, ahogy sikerül bekötni


// Keyboards

#define input_data_bus_DB0 0
#define input_data_bus_DB1 1
#define input_data_bus_DB2 2
#define input_data_bus_DB3 3
#define input_data_bus_DB4 4
#define input_data_bus_DB5 5
#define input_data_bus_DB6 6
#define input_data_bus_DB7 7

#define keyboard_addr_bus_A0 8
#define keyboard_addr_bus_A1 9
#define keyboard_addr_bus_A2 10
#define keyboard_addr_bus__E_great 45  //negált jelet alulvonással kezdem (!E=_E)
#define keyboard_addr_bus__E_swell 46



// Pedals

#define pedal_data_addr_bus_D0 12
#define pedal_data_addr_bus_D1 13
#define pedal_data_addr_bus_D2 14
#define pedal_data_addr_bus_D3 15
#define pedal_data_addr_bus_D4 16
#define pedal_data_addr_bus_D5 17
#define pedal_data_addr_bus_D6 18
#define pedal_data_addr_bus_D7 19

#define pedal_data_addr_bus__S4_0 20
#define pedal_data_addr_bus__S4_1 21
#define pedal_data_addr_bus__S4_2 22
#define pedal_data_addr_bus__S4_3 23



// Stops                        (+transposer amit valszeg nem fogunk használni)

#define stops_addr_bus_A0 33
#define stops_addr_bus_A1 34
#define stops_addr_bus_A2 35
#define stops_addr_bus__E 36
#define stops_addr_bus_DATA 37



// Pistons

#define pistons_data_addr_bus_D0 38  //input data_addr bus, csak ha nem egyesítjük a dolgokat, akkor sztem egyszerűbb lesz
#define pistons_data_addr_bus_D1 39
#define pistons_data_addr_bus_D2 40
#define pistons_data_addr_bus_D3 41
#define pistons_data_addr_bus_D4 42

#define pistons_data_addr_bus__S4_4 43  //ez el van írva a kapcsolási rajzban (_S4_5-re)
#define pistons_data_addr_bus__S4_5 44



// Volumes

#define master_vol A0  //csak analóg pinekre mehetnek!
#define reverb_vol A1
#define great_vol A2
#define pedal_vol A3
#define swell_vol A4  //ennél majd trükközni kell


//  #####################################################################



// Midi
#define BaudRate 115200
#define noteOn 143    //144 = Channel 1 Note on,  145 = Channel 2 Note on,  és akkor majd úgy használhatom, hogy noteOn + channel_number
#define noteOff 127   //128 = Channel 1 Note off, 129 = Channel 2 Note off, és akkor majd úgy használhatom, hogy noteOff + channel_number
#define velocity 127  //a billentyű lenyomás erőssége (ez a maximum érték, és semmi jelentőssége, hogy mennyi, mert nem tudja kezelni az orgona)
//csatornák
#define pedal_ch 1
#define great_ch 2
#define swell_ch 3
#define stops_ch 4
#define piston_ch 5
#define master_vol_ch 6
#define reverb_vol_ch 7
#define great_vol_ch 8
#define pedal_vol_ch 9
#define swell_vol_ch 10



// LEDs
byte stop_state[29] = { 0 };
byte comb = 0;
byte mix = 0;
byte tutti = 0;



// keys
byte keys_cur[61];
byte keys_last[61];



void update_leds(void) {
  digitalWrite(stops_addr_bus_A0, 1);
  digitalWrite(stops_addr_bus_A1, 1);
  digitalWrite(stops_addr_bus_A2, 1);  //CP = 1 és ST = 0

  //értékek beléptetése a shiftregiszterekbe
  digitalWrite(stops_addr_bus_DATA, 0);
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);  //1 óra ciklus a shiftregiszternek, mert az utolsó lábra nincs kötve semmi

  digitalWrite(stops_addr_bus_DATA, tutti == 1);  //majd sorban a jelek visszafelé, óra ciklusokkal elválasztva
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);

  digitalWrite(stops_addr_bus_DATA, mix == 1);
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);

  for (int i = 28; i >= 19; i--) {  //swell registers
    digitalWrite(stops_addr_bus_DATA, stop_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  digitalWrite(stops_addr_bus_DATA, 0);
  for (int i = 0; i < 2; i++) {  //2 unconnected pins
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  for (int i = 16; i >= 9; i--) {  //great registers 1
    digitalWrite(stops_addr_bus_DATA, stop_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  digitalWrite(stops_addr_bus_DATA, 0);
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);  //1 óra ciklus a shiftregiszternek, mert az utolsó lábra nincs kötve semmi

  for (int i = 18; i >= 17; i--) {  //great registers 2
    digitalWrite(stops_addr_bus_DATA, stop_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  for (int i = 5; i >= 1; i--) {  //combs
    digitalWrite(stops_addr_bus_DATA, comb == i);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  for (int i = 8; i >= 1; i--) {  //pedal registers
    digitalWrite(stops_addr_bus_DATA, stop_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  //kimenetek betöltése (egy ST pulzus)
  digitalWrite(stops_addr_bus_A0, 0);
  digitalWrite(stops_addr_bus_A0, 1);
  //végül ST = 0, CP = 1 állásban hagyom a shiftregisztereket, a dekóder kiválasztó lábait pedig 111 állásban
}


void update_keys(void) {
  for (int i = 0; i < 2; i++) {

  }
}


void pins_setup(void) {
  pinMode(input_data_bus_DB0, INPUT_PULLUP);
  pinMode(input_data_bus_DB1, INPUT_PULLUP);
  pinMode(input_data_bus_DB2, INPUT_PULLUP);
  pinMode(input_data_bus_DB3, INPUT_PULLUP);
  pinMode(input_data_bus_DB4, INPUT_PULLUP);
  pinMode(input_data_bus_DB5, INPUT_PULLUP);
  pinMode(input_data_bus_DB6, INPUT_PULLUP);
  pinMode(input_data_bus_DB7, INPUT_PULLUP);

  pinMode(keyboard_addr_bus_A0, OUTPUT);
  pinMode(keyboard_addr_bus_A1, OUTPUT);
  pinMode(keyboard_addr_bus_A2, OUTPUT);
  pinMode(keyboard_addr_bus__E_great, OUTPUT);
  pinMode(keyboard_addr_bus__E_swell, OUTPUT);


  pinMode(pedal_data_addr_bus_D0, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D1, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D2, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D3, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D4, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D5, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D6, INPUT_PULLUP);
  pinMode(pedal_data_addr_bus_D7, INPUT_PULLUP);

  pinMode(pedal_data_addr_bus__S4_0, OUTPUT);
  pinMode(pedal_data_addr_bus__S4_1, OUTPUT);
  pinMode(pedal_data_addr_bus__S4_2, OUTPUT);
  pinMode(pedal_data_addr_bus__S4_3, OUTPUT);


  pinMode(stops_addr_bus_A0, OUTPUT);
  pinMode(stops_addr_bus_A1, OUTPUT);
  pinMode(stops_addr_bus_A2, OUTPUT);
  pinMode(stops_addr_bus__E, OUTPUT);
  pinMode(stops_addr_bus_DATA, OUTPUT);


  pinMode(pistons_data_addr_bus_D0, INPUT_PULLUP);
  pinMode(pistons_data_addr_bus_D1, INPUT_PULLUP);
  pinMode(pistons_data_addr_bus_D2, INPUT_PULLUP);
  pinMode(pistons_data_addr_bus_D3, INPUT_PULLUP);
  pinMode(pistons_data_addr_bus_D4, INPUT_PULLUP);

  pinMode(pistons_data_addr_bus__S4_4, OUTPUT);
  pinMode(pistons_data_addr_bus__S4_5, OUTPUT);


  pinMode(master_vol, INPUT);
  pinMode(reverb_vol, INPUT);
  pinMode(great_vol, INPUT);
  pinMode(pedal_vol, INPUT);
  pinMode(swell_vol, INPUT);
}


void setup() {
  pins_setup();
  Serial.begin(BaudRate);
}


void loop() {
  //MIDImessage(noteOn + pedal_ch, 63, velocity);  //példa küldés
}


void MIDImessage(byte status, byte data1, byte data2) {
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);
}
