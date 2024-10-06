// Port defines  #########################################################
// nevek a kapcs. rajz alapján
// pin számokat majd átírjuk, ahogy sikerül bekötni

//tesztelés utáni verzió
//todo: led panel javítás, analóg bekötés, pedál hiba, esetleg bekötő panel


// Keyboards

#define input_data_bus_DB0 A0  //egymást követő pineknek kell lenniük, növekvő sorrendben
#define input_data_bus_DB1 A1
#define input_data_bus_DB2 A2
#define input_data_bus_DB3 A3
#define input_data_bus_DB4 A4
#define input_data_bus_DB5 A5
#define input_data_bus_DB6 A6
#define input_data_bus_DB7 A7
#define input_data_bus_RST A8


#define keyboard_addr_bus_A0 18
#define keyboard_addr_bus_A1 17
#define keyboard_addr_bus_A2 16
#define keyboard_addr_bus__E_swell 15  //negált jelet alulvonással kezdem (!E=_E)
#define keyboard_addr_bus__E_great 14



// Pedals

#define pedal_addr_data_bus_D0 22  //egymást követő pineknek kell lenniük, növekvő sorrendben
#define pedal_addr_data_bus_D1 23
#define pedal_addr_data_bus_D2 24
#define pedal_addr_data_bus_D3 25
#define pedal_addr_data_bus_D4 26
#define pedal_addr_data_bus_D5 27
#define pedal_addr_data_bus_D6 28
#define pedal_addr_data_bus_D7 29

#define pedal_addr_data_bus__S4_0 30  //egymást követő pineknek kell lenniük, növekvő sorrendben
#define pedal_addr_data_bus__S4_1 31
#define pedal_addr_data_bus__S4_2 32
#define pedal_addr_data_bus__S4_3 33



// Stops                        (+transposer amit valszeg nem fogunk használni)

#define stops_addr_bus_A0 2
#define stops_addr_bus_A1 3
#define stops_addr_bus_A2 4
#define stops_addr_bus__E 5
#define stops_addr_bus_DATA 6



// Pistons

#define pistons_addr_data_bus_D0 40  //input addr_data bus, csak ha nem egyesítjük a dolgokat, akkor sztem egyszerűbb lesz
#define pistons_addr_data_bus_D1 41  //egymást követő pineknek kell lenniük, növekvő sorrendben
#define pistons_addr_data_bus_D2 42
#define pistons_addr_data_bus_D3 43
#define pistons_addr_data_bus_D4 44

#define pistons_addr_data_bus__S4_4 45  //ez el van írva a kapcsolási rajzban (_S4_5-re)
#define pistons_addr_data_bus__S4_5 46



// Volumes

#define reverb_vol A11  //csak analóg pinekre mehetnek!
#define great_vol A12
#define pedal_vol A13
#define swell_vol A14  //ennél majd trükközni kell


//  #####################################################################



// Midi
#define BaudRate 115200
#define noteOn 143    //144 = Channel 1 Note on,  145 = Channel 2 Note on, és akkor majd úgy használhatom, hogy noteOn + channel_number
#define noteOff 127   //128 = Channel 1 Note off, 129 = Channel 2 Note off, és akkor majd úgy használhatom, hogy noteOff + channel_number
#define velocity 127  //a billentyű lenyomás erőssége (ez a maximum érték, és semmi jelentőssége, hogy mennyi, mert nem tudja kezelni az orgona)
#define lowest_note 36
#define controller 175  //hangerő szabályzókhoz, 176 = control change, és akkor majd úgy használhatom, hogy controller + channel_number

//csatornák
#define pedal_ch 1
#define great_ch 2
#define swell_ch 3
#define stops_ch 4
#define piston_ch 5

#define pedal_vol_ch 1
#define great_vol_ch 2
#define swell_vol_ch 3
#define reverb_vol_ch 4
#define receive_ch 1

#define analog_threshold 32



// LEDs
byte leds_state[30];  //1-el több elemet hozok létre, hogy indíthassam 1-től a számozást  //EL VAN SZÁMOZVA ÉS TRÜKKOS A RAJZ!
byte preset = 1;
byte tutti = 1;


// stops
byte stops_cur[30];  //1-el több elemet hozok létre, hogy indíthassam 1-től a számozást
byte stops_last[30];


// keys
byte keys_cur[2][61];  //0: great, 1: swell
byte keys_last[2][61];


// pedals
byte peds_cur[30];
byte peds_last[30];


// pistons
//0-5: preset
//  6: set
//  7: mix
//  8: T
byte pistons_cur[9];
byte pistons_last[9];


// analog
int pedal_vol_last;
int great_vol_last;
int swell_vol_last;
int reverb_vol_last;



void MIDI_send(byte status, byte data1, byte data2) {
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);
}



void MIDI_read() {
  if (Serial.available() > 2) {   //3 bájt egy midi üzenet
    byte status = Serial.read();  //pl: noteOn, noteOff
    byte data1 = Serial.read();   //note
    byte data2 = Serial.read();   //velocity (don't care jelenleg)

    if (data1 < sizeof(leds_state) / sizeof(byte)) {  //csak akkor foglalkozom vele, ha be tudom írni a led_state tömbbe, vagyis az elem számnál kisebb
      if (status == noteOn + receive_ch) {
        leds_state[data1] = 1;
      } else if (status == noteOff + receive_ch) {
        leds_state[data1] = 0;
      }
    }
  }
}



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
      digitalWrite(keyboard_addr_bus_A0, 0);
      digitalWrite(keyboard_addr_bus_A1, 1);
      digitalWrite(keyboard_addr_bus_A2, 1);

      digitalWrite(stops_addr_bus_A0, 0);
      digitalWrite(stops_addr_bus_A1, 1);
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



void read_bus(int bus_first_bit, byte addr[], int element, int n) {  //addr címen lévő tömb element-edik elemétől kezdve n (max 8) darab pin értékét írja be az input data bus-nak
  for (int i = 0; i < n && i < 8; i++) {
    addr[element + i] = digitalRead(bus_first_bit + i);
  }
}



void set_leds(bool state) {
  set_A(7);
  digitalWrite(stops_addr_bus__E, 0);
  digitalWrite(stops_addr_bus_DATA, state);

  for (int i = 0; i < 36; i++) {
    set_A(5); //clock
    set_A(7);
  }
  set_A(6);   //strobe
  set_A(7);
  digitalWrite(stops_addr_bus__E, 0);
}



void update_leds(void) {
  digitalWrite(stops_addr_bus__E, 0);

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

  for (int i = 4; i >= 1; i--) {  //presets 1
    digitalWrite(stops_addr_bus_DATA, preset == i);
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

  digitalWrite(stops_addr_bus_DATA, preset == 5);  //presets 2
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

  digitalWrite(stops_addr_bus__E, 1);
}



void update_leds2(void) {
  set_A(7);  //CP = 1 és ST = 0
  digitalWrite(stops_addr_bus__E, 0);

  for (int i = 0; i < 10; i++) {
    digitalWrite(stops_addr_bus_DATA, 1);
    set_A(5);
    //set_A(7);
    //delay(200);
    set_A(6);
    //delay(200);
    set_A(7);
    delay(200);
    digitalWrite(stops_addr_bus_DATA, 0);
    set_A(5);
    //set_A(7);
    //delay(200);
    set_A(6);
    //delay(200);
    set_A(7);
    delay(200);
  }

  digitalWrite(stops_addr_bus__E, 1);
}



void update_leds3(void) {
  set_A(7);  //CP = 1 és ST = 0
  digitalWrite(stops_addr_bus__E, 0);

  for (int i = 0; i < 10; i++) {
    digitalWrite(stops_addr_bus_DATA, 1);
    set_A(5);
    //set_A(7);
    //delay(200);
    set_A(6);
    //delay(200);
    set_A(7);
    delay(200);
    digitalWrite(stops_addr_bus_DATA, 0);
    set_A(5);
    //set_A(7);
    //delay(200);
    set_A(6);
    //delay(200);
    set_A(7);
    delay(200);
  }

  digitalWrite(stops_addr_bus__E, 1);
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
  //for(int i=0;i<6;i++)
  //peds_cur[8*3+i] = 1;
  //peds_cur[8*3] = digitalRead(pedal_addr_data_bus_D0);
  read_bus(pedal_addr_data_bus_D1, peds_cur, 8 * 3, 6);
  digitalWrite(pedal_addr_data_bus__S4_3, 1);
}



void update_pistons_cur(void) {
  digitalWrite(pistons_addr_data_bus__S4_4, 0);
  //read_bus(pistons_addr_data_bus_D0, pistons_cur, 1, 5);  //1-5
  pistons_cur[1] = digitalRead(pistons_addr_data_bus_D0);
  pistons_cur[2] = digitalRead(pistons_addr_data_bus_D1);
  pistons_cur[3] = digitalRead(pistons_addr_data_bus_D2);
  pistons_cur[4] = digitalRead(pistons_addr_data_bus_D3);
  pistons_cur[5] = digitalRead(pistons_addr_data_bus_D4);
  digitalWrite(pistons_addr_data_bus__S4_4, 1);

  digitalWrite(pistons_addr_data_bus__S4_5, 0);
  pistons_cur[0] = (digitalRead(pistons_addr_data_bus_D1) && digitalRead(pistons_addr_data_bus_D2));  //0 //az invertált logika miatt van &&
  pistons_cur[6] = digitalRead(pistons_addr_data_bus_D0);                                             //set
  pistons_cur[7] = digitalRead(pistons_addr_data_bus_D3);                                             //mix
  pistons_cur[8] = digitalRead(pistons_addr_data_bus_D4);                                             //T
  digitalWrite(pistons_addr_data_bus__S4_5, 1);
}



void compare_and_send(byte cur_array[], byte last_array[], int length, int channel, int shift) {
  for (int i = 0; i < length; i++) {
    if (cur_array[i] == 1 && last_array[i] == 0) {
      MIDI_send(noteOff + channel, i + shift, velocity);  //az invertált logika miatt noteOff kell, ha felfutó él volt
      last_array[i] = cur_array[i];
    } else if (cur_array[i] == 0 && last_array[i] == 1) {
      MIDI_send(noteOn + channel, i + shift, velocity);  //és on, ha lefutó
      last_array[i] = cur_array[i];
    }
  }
}



void analog_update_and_send(int input, int *last, int channel) {
  int cur = analogRead(input);
  if (abs(cur - *last) >= analog_threshold) {
    MIDI_send(controller + channel, channel, (byte)map(cur, 0, 1023, 0, 127));
    *last = cur;
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
  pinMode(input_data_bus_RST, OUTPUT);

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
  digitalWrite(input_data_bus_RST, 0);
  set_leds(1);
  digitalWrite(input_data_bus_RST, 1);

  Serial.begin(BaudRate);
}



void loop() {
  //MIDI_read();

  //uncomment to test with hardware, comment to test without

  //update_stops_cur();
  //update_keys_cur();
  //update_peds_cur();
  //update_pistons_cur();
  //update_leds3();  //led villogtatás

  set_leds(0);
  delay(500);
  set_leds(1);
  delay(500);



  //uncomment to test without hardware, comment to test with hardware
  /*
  digitalWrite(8, leds_state[3]);

  peds_cur[0] = !peds_cur[0];
  keys_cur[0][1] = !keys_cur[0][1];
  keys_cur[1][2] = !keys_cur[1][2];
  stops_cur[3] = !stops_cur[3];

  delay(1000);*/


  //////////////////////////////////////////////////////////////////

  compare_and_send(peds_cur, peds_last, 30, pedal_ch, lowest_note);
  compare_and_send(keys_cur[0], keys_last[0], 61, great_ch, lowest_note);
  compare_and_send(keys_cur[1], keys_last[1], 61, swell_ch, lowest_note);
  compare_and_send(stops_cur, stops_last, 30, stops_ch, 1);
  compare_and_send(pistons_cur, pistons_last, 9, piston_ch, 0);

  /*
  analog_update_and_send(pedal_vol, &pedal_vol_last, pedal_vol_ch);
  analog_update_and_send(great_vol, &great_vol_last, great_vol_ch);
  analog_update_and_send(swell_vol, &swell_vol_last, swell_vol_ch);
  analog_update_and_send(reverb_vol, &reverb_vol_last, reverb_vol_ch);*/
}