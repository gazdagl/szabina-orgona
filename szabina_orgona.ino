// Port defines  #########################################################
// nevek a kapcs. rajz alapján
// pin számokat majd átírjuk, ahogy sikerül bekötni


// Keyboards

#define input_data_bus_DB0 0  //egymást követő pineknek kell lenniük, növekvő sorrendben
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

#define pedal_addr_data_bus_D0 12     //egymást követő pineknek kell lenniük, növekvő sorrendben  
#define pedal_addr_data_bus_D1 13
#define pedal_addr_data_bus_D2 14
#define pedal_addr_data_bus_D3 15
#define pedal_addr_data_bus_D4 16
#define pedal_addr_data_bus_D5 17
#define pedal_addr_data_bus_D6 18
#define pedal_addr_data_bus_D7 19

#define pedal_addr_data_bus__S4_0 20  //egymást követő pineknek kell lenniük, növekvő sorrendben
#define pedal_addr_data_bus__S4_1 21
#define pedal_addr_data_bus__S4_2 22
#define pedal_addr_data_bus__S4_3 23



// Stops                        (+transposer amit valszeg nem fogunk használni)

#define stops_addr_bus_A0 33
#define stops_addr_bus_A1 34
#define stops_addr_bus_A2 35
#define stops_addr_bus__E 36
#define stops_addr_bus_DATA 37



// Pistons

#define pistons_addr_data_bus_D0 38  //input addr_data bus, csak ha nem egyesítjük a dolgokat, akkor sztem egyszerűbb lesz
#define pistons_addr_data_bus_D1 39
#define pistons_addr_data_bus_D2 40
#define pistons_addr_data_bus_D3 41
#define pistons_addr_data_bus_D4 42

#define pistons_addr_data_bus__S4_4 43  //ez el van írva a kapcsolási rajzban (_S4_5-re)
#define pistons_addr_data_bus__S4_5 44



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
byte leds_state[30] = { 0 };  //1-el több elemet hozok létre, hogy indíthassam 1-től a számozást  //EL VAN SZÁMOZVA ÉS TRÜKKOS A RAJZ!
byte comb = 0;
byte tutti = 0;


// stops
byte stops_cur[30];  //1-el több elemet hozok létre, hogy indíthassam 1-től a számozást
byte stops_last[30];


// keys
byte keys_cur[2][61];  //0: great, 1: swell
byte keys_last[2][61];


// pedals
byte peds_cur[30];
byte peds_last[30];



void set_A(int n) {
  switch (n) {
    case 0:
      digitalWrite(keyboard_addr_bus_A0, 0);
      digitalWrite(keyboard_addr_bus_A1, 0);
      digitalWrite(keyboard_addr_bus_A2, 0);

      digitalWrite(stops_addr_bus_A0, 0);
      digitalWrite(stops_addr_bus_A1, 0);
      digitalWrite(stops_addr_bus_A2, 0);
      break;
    case 1:
      digitalWrite(keyboard_addr_bus_A0, 1);
      digitalWrite(keyboard_addr_bus_A1, 0);
      digitalWrite(keyboard_addr_bus_A2, 0);

      digitalWrite(stops_addr_bus_A0, 1);
      digitalWrite(stops_addr_bus_A1, 0);
      digitalWrite(stops_addr_bus_A2, 0);
      break;
    case 2:
      digitalWrite(keyboard_addr_bus_A0, 0);
      digitalWrite(keyboard_addr_bus_A1, 1);
      digitalWrite(keyboard_addr_bus_A2, 0);

      digitalWrite(stops_addr_bus_A0, 0);
      digitalWrite(stops_addr_bus_A1, 1);
      digitalWrite(stops_addr_bus_A2, 0);
      break;
    case 3:
      digitalWrite(keyboard_addr_bus_A0, 1);
      digitalWrite(keyboard_addr_bus_A1, 1);
      digitalWrite(keyboard_addr_bus_A2, 0);

      digitalWrite(stops_addr_bus_A0, 1);
      digitalWrite(stops_addr_bus_A1, 1);
      digitalWrite(stops_addr_bus_A2, 0);
      break;
    case 4:
      digitalWrite(keyboard_addr_bus_A0, 0);
      digitalWrite(keyboard_addr_bus_A1, 0);
      digitalWrite(keyboard_addr_bus_A2, 1);

      digitalWrite(stops_addr_bus_A0, 0);
      digitalWrite(stops_addr_bus_A1, 0);
      digitalWrite(stops_addr_bus_A2, 1);
      break;
    case 5:
      digitalWrite(keyboard_addr_bus_A0, 1);
      digitalWrite(keyboard_addr_bus_A1, 0);
      digitalWrite(keyboard_addr_bus_A2, 1);

      digitalWrite(stops_addr_bus_A0, 1);
      digitalWrite(stops_addr_bus_A1, 0);
      digitalWrite(stops_addr_bus_A2, 1);
      break;
    case 6:
      digitalWrite(keyboard_addr_bus_A0, 1);
      digitalWrite(keyboard_addr_bus_A1, 0);
      digitalWrite(keyboard_addr_bus_A2, 1);

      digitalWrite(stops_addr_bus_A0, 1);
      digitalWrite(stops_addr_bus_A1, 0);
      digitalWrite(stops_addr_bus_A2, 1);
      break;
    case 7:
      digitalWrite(keyboard_addr_bus_A0, 1);
      digitalWrite(keyboard_addr_bus_A1, 1);
      digitalWrite(keyboard_addr_bus_A2, 1);

      digitalWrite(stops_addr_bus_A0, 1);
      digitalWrite(stops_addr_bus_A1, 1);
      digitalWrite(stops_addr_bus_A2, 1);
      break;
    default:
      digitalWrite(keyboard_addr_bus_A0, 0);
      digitalWrite(keyboard_addr_bus_A1, 0);
      digitalWrite(keyboard_addr_bus_A2, 0);

      digitalWrite(stops_addr_bus_A0, 0);
      digitalWrite(stops_addr_bus_A1, 0);
      digitalWrite(stops_addr_bus_A2, 0);
      break;
  }
}



void read_bus(int bus_first_bit, byte* addr, int element, int n) {  //addr címen lévő tömb element-edik elemétől kezdve n (max 8) darab pin értékét írja be az input data bus-nak
  for (int i = 0; i < n && i < 8; i++) {
    addr[element + i] = digitalRead(bus_first_bit + i);
  }
}



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

  digitalWrite(stops_addr_bus_DATA, leds_state[15] == 1);  //mix
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);

  for (int i = 29; i >= 19; i--) {  //swell registers
    digitalWrite(stops_addr_bus_DATA, leds_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  digitalWrite(stops_addr_bus_DATA, 0);
  for (int i = 0; i < 2; i++) {  //2 unconnected pins
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  for (int i = 12; i >= 9; i--) {  //great registers 1
    digitalWrite(stops_addr_bus_DATA, leds_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  for (int i = 16; i >= 13; i--) {  //great registers 2
    digitalWrite(stops_addr_bus_DATA, leds_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  for (int i = 4; i >= 1; i--) {  //combs 1
    digitalWrite(stops_addr_bus_DATA, comb == i);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  digitalWrite(stops_addr_bus_DATA, 0);
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);  //1 óra ciklus a shiftregiszternek, mert az utolsó lábra nincs kötve semmi

  for (int i = 18; i >= 17; i--) {  //great registers 3
    digitalWrite(stops_addr_bus_DATA, leds_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  digitalWrite(stops_addr_bus_DATA, comb == 5);  //combs 2
  digitalWrite(stops_addr_bus_A1, 0);
  digitalWrite(stops_addr_bus_A1, 1);


  for (int i = 8; i >= 1; i--) {  //pedal registers
    digitalWrite(stops_addr_bus_DATA, leds_state[i] == 1);
    digitalWrite(stops_addr_bus_A1, 0);
    digitalWrite(stops_addr_bus_A1, 1);
  }

  //kimenetek betöltése (egy ST pulzus)
  digitalWrite(stops_addr_bus_A0, 0);
  digitalWrite(stops_addr_bus_A0, 1);
  //végül ST = 0, CP = 1 állásban hagyom a shiftregisztereket, a dekóder kiválasztó lábait pedig 111 állásban
}


void update_stops_cur(void) {
  digitalWrite(stops_addr_bus__E, 0);

  for (int j = 0; j < 3; j++) {
    set_A(j);
    read_bus(input_data_bus_DB0, stops_cur, 8 * j, 8);
  }
  set_A(3);
  read_bus(input_data_bus_DB0, stops_cur, 8 * 3, 5);

  digitalWrite(stops_addr_bus__E, 1);
}


void update_keys_cur(void) {
  for (int i = 0; i < 2; i++) {
    if (i == 0)
      digitalWrite(keyboard_addr_bus__E_great, 0);
    else
      digitalWrite(keyboard_addr_bus__E_swell, 0);

    for (int j = 0; j < 7; j++) {
      set_A(j);
      read_bus(input_data_bus_DB0, keys_cur[i], 8 * j, 8);
    }

    set_A(7);
    read_bus(input_data_bus_DB0, keys_cur[i], 8 * 7, 5);

    digitalWrite(keyboard_addr_bus__E_great, 1);
    digitalWrite(keyboard_addr_bus__E_swell, 1);
  }
}


void update_peds_cur(void) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pedal_addr_data_bus__S4_0 + i, 0);
    read_bus(pedal_addr_data_bus_D0, peds_cur, 8 * i, 8);
    digitalWrite(pedal_addr_data_bus__S4_0 + i, 1);
  }

  digitalWrite(pedal_addr_data_bus__S4_3, 0);
  read_bus(pedal_addr_data_bus_D0, peds_cur, 8 * 3, 6);
  digitalWrite(pedal_addr_data_bus__S4_3, 1);
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


  pinMode(pedal_addr_data_bus_D0, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D1, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D2, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D3, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D4, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D5, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D6, INPUT_PULLUP);
  pinMode(pedal_addr_data_bus_D7, INPUT_PULLUP);

  pinMode(pedal_addr_data_bus__S4_0, OUTPUT);
  pinMode(pedal_addr_data_bus__S4_1, OUTPUT);
  pinMode(pedal_addr_data_bus__S4_2, OUTPUT);
  pinMode(pedal_addr_data_bus__S4_3, OUTPUT);


  pinMode(stops_addr_bus_A0, OUTPUT);
  pinMode(stops_addr_bus_A1, OUTPUT);
  pinMode(stops_addr_bus_A2, OUTPUT);
  pinMode(stops_addr_bus__E, OUTPUT);
  pinMode(stops_addr_bus_DATA, OUTPUT);


  pinMode(pistons_addr_data_bus_D0, INPUT_PULLUP);
  pinMode(pistons_addr_data_bus_D1, INPUT_PULLUP);
  pinMode(pistons_addr_data_bus_D2, INPUT_PULLUP);
  pinMode(pistons_addr_data_bus_D3, INPUT_PULLUP);
  pinMode(pistons_addr_data_bus_D4, INPUT_PULLUP);

  pinMode(pistons_addr_data_bus__S4_4, OUTPUT);
  pinMode(pistons_addr_data_bus__S4_5, OUTPUT);


  pinMode(master_vol, INPUT);
  pinMode(reverb_vol, INPUT);
  pinMode(great_vol, INPUT);
  pinMode(pedal_vol, INPUT);
  pinMode(swell_vol, INPUT);
}


void setup() {
  pins_setup();

  //letiltok mindent, ami meghajtja az input data bust
  digitalWrite(stops_addr_bus__E, 1);

  digitalWrite(keyboard_addr_bus__E_great, 1);
  digitalWrite(keyboard_addr_bus__E_swell, 1);

  digitalWrite(pedal_addr_data_bus__S4_0, 1);
  digitalWrite(pedal_addr_data_bus__S4_1, 1);
  digitalWrite(pedal_addr_data_bus__S4_2, 1);
  digitalWrite(pedal_addr_data_bus__S4_3, 1);

  digitalWrite(pistons_addr_data_bus__S4_4, 1);
  digitalWrite(pistons_addr_data_bus__S4_5, 1);

  Serial.begin(BaudRate);
}


void loop() {
  //MIDImessage(noteOn + pedal_ch, 63, velocity);  //példa küldés
  update_stops_cur();
  update_keys_cur();
  update_peds_cur();
}


void MIDImessage(byte status, byte data1, byte data2) {
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);
}
