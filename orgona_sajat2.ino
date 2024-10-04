int ped[32];
int man1[64];
int man2[64];
int man3[64];
int man4[64];
int gomb[64];

int lped[32] = {1};
int lman1[64] = {1};
int lman2[64] = {1};
int lman3[64] = {1};
int lman4[64] = {1};
int lgomb[64] = {1};

int noteOn1 = 144;
int noteOff1 = 128;
int noteOn2 = 145;
int noteOff2 = 129;
int noteOn3 = 146;
int noteOff3 = 130;
int noteOn4 = 147;
int noteOff4 = 131;
int noteOn5 = 148;
int noteOff5 = 132;
int noteOn6 = 149;
int noteOff6 = 133;
int velocity = 100;
int chan6 = 181;
int chan7 = 182;
int chan8 = 183;
int Exp = 11;

int LastPot6 = 1;
int LastPot7 = 1;
int LastPot8 = 1;

int nyomva=0;

byte command;
byte note;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  //pinMode(39, INPUT); //nincs használva szegény :(
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);
  pinMode(44, INPUT);
  pinMode(45, INPUT);
  pinMode(46, INPUT);
  pinMode(47, INPUT);
  pinMode(48, INPUT);
  pinMode(49, INPUT);
  pinMode(50, INPUT);
  pinMode(51, INPUT);
  pinMode(52, INPUT);
  pinMode(53, INPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
}

void loop() {
  if(nyomva<0) nyomva=0;
  if(nyomva>0) digitalWrite(LED_BUILTIN, HIGH);
  else if(nyomva==0) digitalWrite(LED_BUILTIN, LOW);
/*
if(Serial.available()>2){
  command=Serial.read();
  note=Serial.read();
  Serial.read();
  if(command==144) digitalWrite(LED_BUILTIN, HIGH);
  if(command==128) digitalWrite(LED_BUILTIN, LOW);}
  */
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  //pinMode(39, INPUT_PULLUP); //nincs használva szegény :(
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(46, INPUT_PULLUP);
  pinMode(47, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
  pinMode(52, INPUT_PULLUP);
  pinMode(53, INPUT_PULLUP);


  //ped
  pinMode(A15, OUTPUT);
  digitalWrite(A15, LOW);
  ped[0] = digitalRead(22);
  ped[1] = digitalRead(23);
  ped[2] = digitalRead(24);
  ped[3] = digitalRead(25);
  ped[4] = digitalRead(26);
  ped[5] = digitalRead(27);
  ped[6] = digitalRead(28);
  ped[7] = digitalRead(29);
  ped[8] = digitalRead(30);
  ped[9] = digitalRead(31);
  ped[10] = digitalRead(32);
  ped[11] = digitalRead(33);
  ped[12] = digitalRead(34);
  ped[13] = digitalRead(35);
  ped[14] = digitalRead(36);
  ped[15] = digitalRead(37);
  ped[16] = digitalRead(38);
  //ped[17] = digitalRead(39);
  ped[18] = digitalRead(40);
  ped[19] = digitalRead(41);
  ped[20] = digitalRead(42);
  ped[21] = digitalRead(43);
  ped[22] = digitalRead(44);
  ped[23] = digitalRead(45);
  ped[24] = digitalRead(46);
  ped[25] = digitalRead(47);
  ped[26] = digitalRead(48);
  ped[27] = digitalRead(49);
  ped[28] = digitalRead(50);
  ped[29] = digitalRead(51);
  ped[30] = digitalRead(52);
  ped[31] = digitalRead(53);
  pinMode(A15, INPUT);


  //man1
  pinMode(A14, OUTPUT);
  digitalWrite(A14, LOW);
  man1[0] = digitalRead(22);
  man1[1] = digitalRead(23);
  man1[2] = digitalRead(24);
  man1[3] = digitalRead(25);
  man1[4] = digitalRead(26);
  man1[5] = digitalRead(27);
  man1[6] = digitalRead(28);
  man1[7] = digitalRead(29);
  man1[8] = digitalRead(30);
  man1[9] = digitalRead(31);
  man1[10] = digitalRead(32);
  man1[11] = digitalRead(33);
  man1[12] = digitalRead(34);
  man1[13] = digitalRead(35);
  man1[14] = digitalRead(36);
  man1[15] = digitalRead(37);
  man1[16] = digitalRead(38);
  //man1[17] = digitalRead(39);
  man1[18] = digitalRead(40);
  man1[19] = digitalRead(41);
  man1[20] = digitalRead(42);
  man1[21] = digitalRead(43);
  man1[22] = digitalRead(44);
  man1[23] = digitalRead(45);
  man1[24] = digitalRead(46);
  man1[25] = digitalRead(47);
  man1[26] = digitalRead(48);
  man1[27] = digitalRead(49);
  man1[28] = digitalRead(50);
  man1[29] = digitalRead(51);
  man1[30] = digitalRead(52);
  man1[31] = digitalRead(53);
  pinMode(A14, INPUT);

  pinMode(A13, OUTPUT);
  digitalWrite(A13, LOW);
  man1[32] = digitalRead(22);
  man1[33] = digitalRead(23);
  man1[34] = digitalRead(24);
  man1[35] = digitalRead(25);
  man1[36] = digitalRead(26);
  man1[37] = digitalRead(27);
  man1[38] = digitalRead(28);
  man1[39] = digitalRead(29);
  man1[40] = digitalRead(30);
  man1[41] = digitalRead(31);
  man1[42] = digitalRead(32);
  man1[43] = digitalRead(33);
  man1[44] = digitalRead(34);
  man1[45] = digitalRead(35);
  man1[46] = digitalRead(36);
  man1[47] = digitalRead(37);
  man1[48] = digitalRead(38);
  //man1[49] = digitalRead(39);
  man1[50] = digitalRead(40);
  man1[51] = digitalRead(41);
  man1[52] = digitalRead(42);
  man1[53] = digitalRead(43);
  man1[54] = digitalRead(44);
  man1[55] = digitalRead(45);
  man1[56] = digitalRead(46);
  man1[57] = digitalRead(47);
  man1[58] = digitalRead(48);
  man1[59] = digitalRead(49);
  man1[60] = digitalRead(50);
  man1[61] = digitalRead(51);
  man1[62] = digitalRead(52);
  man1[63] = digitalRead(53);
  pinMode(A13, INPUT);


  //man2
  pinMode(A12, OUTPUT);
  digitalWrite(A12, LOW);
  man2[0] = digitalRead(22);
  man2[1] = digitalRead(23);
  man2[2] = digitalRead(24);
  man2[3] = digitalRead(25);
  man2[4] = digitalRead(26);
  man2[5] = digitalRead(27);
  man2[6] = digitalRead(28);
  man2[7] = digitalRead(29);
  man2[8] = digitalRead(30);
  man2[9] = digitalRead(31);
  man2[10] = digitalRead(32);
  man2[11] = digitalRead(33);
  man2[12] = digitalRead(34);
  man2[13] = digitalRead(35);
  man2[14] = digitalRead(36);
  man2[15] = digitalRead(37);
  man2[16] = digitalRead(38);
  //man2[17] = digitalRead(39);
  man2[18] = digitalRead(40);
  man2[19] = digitalRead(41);
  man2[20] = digitalRead(42);
  man2[21] = digitalRead(43);
  man2[22] = digitalRead(44);
  man2[23] = digitalRead(45);
  man2[24] = digitalRead(46);
  man2[25] = digitalRead(47);
  man2[26] = digitalRead(48);
  man2[27] = digitalRead(49);
  man2[28] = digitalRead(50);
  man2[29] = digitalRead(51);
  man2[30] = digitalRead(52);
  man2[31] = digitalRead(53);
  pinMode(A12, INPUT);

  pinMode(A11, OUTPUT);
  digitalWrite(A11, LOW);
  man2[32] = digitalRead(22);
  man2[33] = digitalRead(23);
  man2[34] = digitalRead(24);
  man2[35] = digitalRead(25);
  man2[36] = digitalRead(26);
  man2[37] = digitalRead(27);
  man2[38] = digitalRead(28);
  man2[39] = digitalRead(29);
  man2[40] = digitalRead(30);
  man2[41] = digitalRead(31);
  man2[42] = digitalRead(32);
  man2[43] = digitalRead(33);
  man2[44] = digitalRead(34);
  man2[45] = digitalRead(35);
  man2[46] = digitalRead(36);
  man2[47] = digitalRead(37);
  man2[48] = digitalRead(38);
  //man2[49] = digitalRead(39);
  man2[50] = digitalRead(40);
  man2[51] = digitalRead(41);
  man2[52] = digitalRead(42);
  man2[53] = digitalRead(43);
  man2[54] = digitalRead(44);
  man2[55] = digitalRead(45);
  man2[56] = digitalRead(46);
  man2[57] = digitalRead(47);
  man2[58] = digitalRead(48);
  man2[59] = digitalRead(49);
  man2[60] = digitalRead(50);
  man2[61] = digitalRead(51);
  man2[62] = digitalRead(52);
  man2[63] = digitalRead(53);
  pinMode(A11, INPUT);


  //man3
  pinMode(A10, OUTPUT);
  digitalWrite(A10, LOW);
  man3[0] = digitalRead(22);
  man3[1] = digitalRead(23);
  man3[2] = digitalRead(24);
  man3[3] = digitalRead(25);
  man3[4] = digitalRead(26);
  man3[5] = digitalRead(27);
  man3[6] = digitalRead(28);
  man3[7] = digitalRead(29);
  man3[8] = digitalRead(30);
  man3[9] = digitalRead(31);
  man3[10] = digitalRead(32);
  man3[11] = digitalRead(33);
  man3[12] = digitalRead(34);
  man3[13] = digitalRead(35);
  man3[14] = digitalRead(36);
  man3[15] = digitalRead(37);
  man3[16] = digitalRead(38);
  //man3[17] = digitalRead(39);
  man3[18] = digitalRead(40);
  man3[19] = digitalRead(41);
  man3[20] = digitalRead(42);
  man3[21] = digitalRead(43);
  man3[22] = digitalRead(44);
  man3[23] = digitalRead(45);
  man3[24] = digitalRead(46);
  man3[25] = digitalRead(47);
  man3[26] = digitalRead(48);
  man3[27] = digitalRead(49);
  man3[28] = digitalRead(50);
  man3[29] = digitalRead(51);
  man3[30] = digitalRead(52);
  man3[31] = digitalRead(53);
  pinMode(A10, INPUT);

  pinMode(A9, OUTPUT);
  digitalWrite(A9, LOW);
  man3[32] = digitalRead(22);
  man3[33] = digitalRead(23);
  man3[34] = digitalRead(24);
  man3[35] = digitalRead(25);
  man3[36] = digitalRead(26);
  man3[37] = digitalRead(27);
  man3[38] = digitalRead(28);
  man3[39] = digitalRead(29);
  man3[40] = digitalRead(30);
  man3[41] = digitalRead(31);
  man3[42] = digitalRead(32);
  man3[43] = digitalRead(33);
  man3[44] = digitalRead(34);
  man3[45] = digitalRead(35);
  man3[46] = digitalRead(36);
  man3[47] = digitalRead(37);
  man3[48] = digitalRead(38);
  //man3[49] = digitalRead(39);
  man3[50] = digitalRead(40);
  man3[51] = digitalRead(41);
  man3[52] = digitalRead(42);
  man3[53] = digitalRead(43);
  man3[54] = digitalRead(44);
  man3[55] = digitalRead(45);
  man3[56] = digitalRead(46);
  man3[57] = digitalRead(47);
  man3[58] = digitalRead(48);
  man3[59] = digitalRead(49);
  man3[60] = digitalRead(50);
  man3[61] = digitalRead(51);
  man3[62] = digitalRead(52);
  man3[63] = digitalRead(53);
  pinMode(A9, INPUT);


  //man4
  pinMode(A8, OUTPUT);
  digitalWrite(A8, LOW);
  man4[0] = digitalRead(22);
  man4[1] = digitalRead(23);
  man4[2] = digitalRead(24);
  man4[3] = digitalRead(25);
  man4[4] = digitalRead(26);
  man4[5] = digitalRead(27);
  man4[6] = digitalRead(28);
  man4[7] = digitalRead(29);
  man4[8] = digitalRead(30);
  man4[9] = digitalRead(31);
  man4[10] = digitalRead(32);
  man4[11] = digitalRead(33);
  man4[12] = digitalRead(34);
  man4[13] = digitalRead(35);
  man4[14] = digitalRead(36);
  man4[15] = digitalRead(37);
  man4[16] = digitalRead(38);
  //man4[17] = digitalRead(39);
  man4[18] = digitalRead(40);
  man4[19] = digitalRead(41);
  man4[20] = digitalRead(42);
  man4[21] = digitalRead(43);
  man4[22] = digitalRead(44);
  man4[23] = digitalRead(45);
  man4[24] = digitalRead(46);
  man4[25] = digitalRead(47);
  man4[26] = digitalRead(48);
  man4[27] = digitalRead(49);
  man4[28] = digitalRead(50);
  man4[29] = digitalRead(51);
  man4[30] = digitalRead(52);
  man4[31] = digitalRead(53);
  pinMode(A8, INPUT);

  pinMode(A7, OUTPUT);
  digitalWrite(A7, LOW);
  man4[32] = digitalRead(22);
  man4[33] = digitalRead(23);
  man4[34] = digitalRead(24);
  man4[35] = digitalRead(25);
  man4[36] = digitalRead(26);
  man4[37] = digitalRead(27);
  man4[38] = digitalRead(28);
  man4[39] = digitalRead(29);
  man4[40] = digitalRead(30);
  man4[41] = digitalRead(31);
  man4[42] = digitalRead(32);
  man4[43] = digitalRead(33);
  man4[44] = digitalRead(34);
  man4[45] = digitalRead(35);
  man4[46] = digitalRead(36);
  man4[47] = digitalRead(37);
  man4[48] = digitalRead(38);
  //man4[49] = digitalRead(39);
  man4[50] = digitalRead(40);
  man4[51] = digitalRead(41);
  man4[52] = digitalRead(42);
  man4[53] = digitalRead(43);
  man4[54] = digitalRead(44);
  man4[55] = digitalRead(45);
  man4[56] = digitalRead(46);
  man4[57] = digitalRead(47);
  man4[58] = digitalRead(48);
  man4[59] = digitalRead(49);
  man4[60] = digitalRead(50);
  man4[61] = digitalRead(51);
  man4[62] = digitalRead(52);
  man4[63] = digitalRead(53);
  pinMode(A7, INPUT);

  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  //pinMode(39, INPUT); //nincs használva szegény :(
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);
  pinMode(44, INPUT);
  pinMode(45, INPUT);
  pinMode(46, INPUT);
  pinMode(47, INPUT);
  pinMode(48, INPUT);
  pinMode(49, INPUT);
  pinMode(50, INPUT);
  pinMode(51, INPUT);
  pinMode(52, INPUT);
  pinMode(53, INPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  

  //write ped/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (ped[0] == 0 and lped[0]==1) {
    MidiSend(noteOn1, 42, velocity);
    lped[0] = 0;
    nyomva++;
  }
  else if (ped[0] == 1 and lped[0]==0) {
    MidiSend(noteOff1, 42, velocity);
    lped[0] = 1;
    nyomva--;
  }
  if (ped[1] == 0 and lped[1]==1) {
    MidiSend(noteOn1, 41, velocity);
    lped[1] = 0;
    nyomva++;
  }
  else if (ped[1] == 1 and lped[1]==0) {
    MidiSend(noteOff1, 41, velocity);
    lped[1] = 1;
    nyomva--;
  }
  if (ped[2] == 0 and lped[2]==1) {
    MidiSend(noteOn1, 43, velocity);
    lped[2] = 0;
    nyomva++;
  }
  else if (ped[2] == 1 and lped[2]==0) {
    MidiSend(noteOff1, 43, velocity);
    lped[2] = 1;
    nyomva--;
  }
  if (ped[3] == 0 and lped[3]==1) {
    MidiSend(noteOn1, 40, velocity);
    lped[3] = 0;
    nyomva++;
  }
  else if (ped[3] == 1 and lped[3]==0) {
    MidiSend(noteOff1, 40, velocity);
    lped[3] = 1;
    nyomva--;
  }
  if (ped[4] == 0 and lped[4]==1) {
    MidiSend(noteOn1, 44, velocity);
    lped[4] = 0;
    nyomva++;
  }
  else if (ped[4] == 1 and lped[4]==0) {
    MidiSend(noteOff1, 44, velocity);
    lped[4] = 1;
    nyomva--;
  }
  if (ped[5] == 0 and lped[5]==1) {
    MidiSend(noteOn1, 39, velocity);
    lped[5] = 0;
    nyomva++;
  }
  else if (ped[5] == 1 and lped[5]==0) {
    MidiSend(noteOff1, 39, velocity);
    lped[5] = 1;
    nyomva--;
  }
  if (ped[6] == 0 and lped[6]==1) {
    MidiSend(noteOn1, 45, velocity);
    lped[6] = 0;
    nyomva++;
  }
  else if (ped[6] == 1 and lped[6]==0) {
    MidiSend(noteOff1, 45, velocity);
    lped[6] = 1;
    nyomva--;
  }
  if (ped[7] == 0 and lped[7]==1) {
    MidiSend(noteOn1, 38, velocity);
    lped[7] = 0;
    nyomva++;
  }
  else if (ped[7] == 1 and lped[7]==0) {
    MidiSend(noteOff1, 38, velocity);
    lped[7] = 1;
    nyomva--;
  }
  if (ped[8] == 0 and lped[8]==1) {
    MidiSend(noteOn1, 46, velocity);
    lped[8] = 0;
    nyomva++;
  }
  else if (ped[8] == 1 and lped[8]==0) {
    MidiSend(noteOff1, 46, velocity);
    lped[8] = 1;
    nyomva--;
  }
  if (ped[9] == 0 and lped[9]==1) {
    MidiSend(noteOn1, 37, velocity);
    lped[9] = 0;
    nyomva++;
  }
  else if (ped[9] == 1 and lped[9]==0) {
    MidiSend(noteOff1, 37, velocity);
    lped[9] = 1;
    nyomva--;
  }
  if (ped[10] == 0 and lped[10]==1) {
    MidiSend(noteOn1, 47, velocity);
    lped[10] = 0;
    nyomva++;
  }
  else if (ped[10] == 1 and lped[10]==0) {
    MidiSend(noteOff1, 47, velocity);
    lped[10] = 1;
    nyomva--;
  }
  if (ped[11] == 0 and lped[11]==1) {
    MidiSend(noteOn1, 36, velocity);
    lped[11] = 0;
    nyomva++;
  }
  else if (ped[11] == 1 and lped[11]==0) {
    MidiSend(noteOff1, 36, velocity);
    lped[11] = 1;
    nyomva--;
  }
  if (ped[12] == 0 and lped[12]==1) {
    MidiSend(noteOn1, 48, velocity);
    lped[12] = 0;
    nyomva++;
  }
  else if (ped[12] == 1 and lped[12]==0) {
    MidiSend(noteOff1, 48, velocity);
    lped[12] = 1;
    nyomva--;
  }
  if (ped[13] == 0 and lped[13]==1) {
    MidiSend(noteOn1, 59, velocity);
    lped[13] = 0;
    nyomva++;
  }
  else if (ped[13] == 1 and lped[13]==0) {
    MidiSend(noteOff1, 59, velocity);
    lped[13] = 1;
    nyomva--;
  }
  if (ped[14] == 0 and lped[14]==1) {
    MidiSend(noteOn1, 49, velocity);
    lped[14] = 0;
    nyomva++;
  }
  else if (ped[14] == 1 and lped[14]==0) {
    MidiSend(noteOff1, 49, velocity);
    lped[14] = 1;
    nyomva--;
  }
  if (ped[15] == 0 and lped[15]==1) {
    MidiSend(noteOn1, 58, velocity);
    lped[15] = 0;
    nyomva++;
  }
  else if (ped[15] == 1 and lped[15]==0) {
    MidiSend(noteOff1, 58, velocity);
    lped[15] = 1;
    nyomva--;
  }
  if (ped[16] == 0 and lped[16]==1) {
    MidiSend(noteOn1, 50, velocity);
    lped[16] = 0;
    nyomva++;
  }
  else if (ped[16] == 1 and lped[16]==0) {
    MidiSend(noteOff1, 50, velocity);
    lped[16] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (ped[17] == 0 and lped[17]==1) {
    MidiSend(noteOn1, ??, velocity);
    lped[17] = 0;
    nyomva++;
  }
  else if (ped[17] == 1 and lped[17]==0) {
    MidiSend(noteOff1, ??, velocity);
    lped[17] = 1;
    nyomva--;
  }
  */
  if (ped[18] == 0 and lped[18]==1) {
    MidiSend(noteOn1, 51, velocity);
    lped[18] = 0;
    nyomva++;
  }
  else if (ped[18] == 1 and lped[18]==0) {
    MidiSend(noteOff1, 51, velocity);
    lped[18] = 1;
    nyomva--;
  }
  if (ped[19] == 0 and lped[19]==1) {
    MidiSend(noteOn1, 66, velocity);
    lped[19] = 0;
    nyomva++;
  }
  else if (ped[19] == 1 and lped[19]==0) {
    MidiSend(noteOff1, 66, velocity);
    lped[19] = 1;
    nyomva--;
  }
  if (ped[20] == 0 and lped[20]==1) {
    MidiSend(noteOn1, 52, velocity);
    lped[20] = 0;
    nyomva++;
  }
  else if (ped[20] == 1 and lped[20]==0) {
    MidiSend(noteOff1, 52, velocity);
    lped[20] = 1;
    nyomva--;
  }
  if (ped[21] == 0 and lped[21]==1) {
    MidiSend(noteOn1, 65, velocity);
    lped[21] = 0;
    nyomva++;
  }
  else if (ped[21] == 1 and lped[21]==0) {
    MidiSend(noteOff1, 65, velocity);
    lped[21] = 1;
    nyomva--;
  }
  if (ped[22] == 0 and lped[22]==1) {
    MidiSend(noteOn1, 53, velocity);
    lped[22] = 0;
    nyomva++;
  }
  else if (ped[22] == 1 and lped[22]==0) {
    MidiSend(noteOff1, 53, velocity);
    lped[22] = 1;
    nyomva--;
  }
  if (ped[23] == 0 and lped[23]==1) {
    MidiSend(noteOn1, 64, velocity);
    lped[23] = 0;
    nyomva++;
  }
  else if (ped[23] == 1 and lped[23]==0) {
    MidiSend(noteOff1, 64, velocity);
    lped[23] = 1;
    nyomva--;
  }
  if (ped[24] == 0 and lped[24]==1) {
    MidiSend(noteOn1, 54, velocity);
    lped[24] = 0;
    nyomva++;
  }
  else if (ped[24] == 1 and lped[24]==0) {
    MidiSend(noteOff1, 54, velocity);
    lped[24] = 1;
    nyomva--;
  }
  if (ped[25] == 0 and lped[25]==1) {
    MidiSend(noteOn1, 63, velocity);
    lped[25] = 0;
    nyomva++;
  }
  else if (ped[25] == 1 and lped[25]==0) {
    MidiSend(noteOff1, 63, velocity);
    lped[25] = 1;
    nyomva--;
  }
  if (ped[26] == 0 and lped[26]==1) {
    MidiSend(noteOn1, 55, velocity);
    lped[26] = 0;
    nyomva++;
  }
  else if (ped[26] == 1 and lped[26]==0) {
    MidiSend(noteOff1, 55, velocity);
    lped[26] = 1;
    nyomva--;
  }
  if (ped[27] == 0 and lped[27]==1) {
    MidiSend(noteOn1, 62, velocity);
    lped[27] = 0;
    nyomva++;
  }
  else if (ped[27] == 1 and lped[27]==0) {
    MidiSend(noteOff1, 62, velocity);
    lped[27] = 1;
    nyomva--;
  }
  if (ped[28] == 0 and lped[28]==1) {
    MidiSend(noteOn1, 56, velocity);
    lped[28] = 0;
    nyomva++;
  }
  else if (ped[28] == 1 and lped[28]==0) {
    MidiSend(noteOff1, 56, velocity);
    lped[28] = 1;
    nyomva--;
  }
  if (ped[29] == 0 and lped[29]==1) {
    MidiSend(noteOn1, 61, velocity);
    lped[29] = 0;
    nyomva++;
  }
  else if (ped[29] == 1 and lped[29]==0) {
    MidiSend(noteOff1, 61, velocity);
    lped[29] = 1;
    nyomva--;
  }
  if (ped[30] == 0 and lped[30]==1) {
    MidiSend(noteOn1, 57, velocity);
    lped[30] = 0;
    nyomva++;
  }
  else if (ped[30] == 1 and lped[30]==0) {
    MidiSend(noteOff1, 57, velocity);
    lped[30] = 1;
    nyomva--;
  }
  if (ped[31] == 0 and lped[31]==1) {
    MidiSend(noteOn1, 60, velocity);
    lped[31] = 0;
    nyomva++;
  }
  else if (ped[31] == 1 and lped[31]==0) {
    MidiSend(noteOff1, 60, velocity);
    lped[31] = 1;
    nyomva--;
  }


  //write man1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (man1[0] == 0 and lman1[0]==1) {
    MidiSend(noteOn2, 42, velocity);
    lman1[0] = 0;
    nyomva++;
  }
  else if (man1[0] == 1 and lman1[0]==0) {
    MidiSend(noteOff2, 42, velocity);
    lman1[0] = 1;
    nyomva--;
  }
  if (man1[1] == 0 and lman1[1]==1) {
    MidiSend(noteOn2, 41, velocity);
    lman1[1] = 0;
    nyomva++;
  }
  else if (man1[1] == 1 and lman1[1]==0) {
    MidiSend(noteOff2, 41, velocity);
    lman1[1] = 1;
    nyomva--;
  }
  if (man1[2] == 0 and lman1[2]==1) {
    MidiSend(noteOn2, 43, velocity);
    lman1[2] = 0;
    nyomva++;
  }
  else if (man1[2] == 1 and lman1[2]==0) {
    MidiSend(noteOff2, 43, velocity);
    lman1[2] = 1;
    nyomva--;
  }
  if (man1[3] == 0 and lman1[3]==1) {
    MidiSend(noteOn2, 40, velocity);
    lman1[3] = 0;
    nyomva++;
  }
  else if (man1[3] == 1 and lman1[3]==0) {
    MidiSend(noteOff2, 40, velocity);
    lman1[3] = 1;
    nyomva--;
  }
  if (man1[4] == 0 and lman1[4]==1) {
    MidiSend(noteOn2, 44, velocity);
    lman1[4] = 0;
    nyomva++;
  }
  else if (man1[4] == 1 and lman1[4]==0) {
    MidiSend(noteOff2, 44, velocity);
    lman1[4] = 1;
    nyomva--;
  }
  if (man1[5] == 0 and lman1[5]==1) {
    MidiSend(noteOn2, 39, velocity);
    lman1[5] = 0;
    nyomva++;
  }
  else if (man1[5] == 1 and lman1[5]==0) {
    MidiSend(noteOff2, 39, velocity);
    lman1[5] = 1;
    nyomva--;
  }
  if (man1[6] == 0 and lman1[6]==1) {
    MidiSend(noteOn2, 45, velocity);
    lman1[6] = 0;
    nyomva++;
  }
  else if (man1[6] == 1 and lman1[6]==0) {
    MidiSend(noteOff2, 45, velocity);
    lman1[6] = 1;
    nyomva--;
  }
  if (man1[7] == 0 and lman1[7]==1) {
    MidiSend(noteOn2, 38, velocity);
    lman1[7] = 0;
    nyomva++;
  }
  else if (man1[7] == 1 and lman1[7]==0) {
    MidiSend(noteOff2, 38, velocity);
    lman1[7] = 1;
    nyomva--;
  }
  if (man1[8] == 0 and lman1[8]==1) {
    MidiSend(noteOn2, 46, velocity);
    lman1[8] = 0;
    nyomva++;
  }
  else if (man1[8] == 1 and lman1[8]==0) {
    MidiSend(noteOff2, 46, velocity);
    lman1[8] = 1;
    nyomva--;
  }
  if (man1[9] == 0 and lman1[9]==1) {
    MidiSend(noteOn2, 37, velocity);
    lman1[9] = 0;
    nyomva++;
  }
  else if (man1[9] == 1 and lman1[9]==0) {
    MidiSend(noteOff2, 37, velocity);
    lman1[9] = 1;
    nyomva--;
  }
  if (man1[10] == 0 and lman1[10]==1) {
    MidiSend(noteOn2, 47, velocity);
    lman1[10] = 0;
    nyomva++;
  }
  else if (man1[10] == 1 and lman1[10]==0) {
    MidiSend(noteOff2, 47, velocity);
    lman1[10] = 1;
    nyomva--;
  }
  if (man1[11] == 0 and lman1[11]==1) {
    MidiSend(noteOn2, 36, velocity);
    lman1[11] = 0;
    nyomva++;
  }
  else if (man1[11] == 1 and lman1[11]==0) {
    MidiSend(noteOff2, 36, velocity);
    lman1[11] = 1;
    nyomva--;
  }
  if (man1[12] == 0 and lman1[12]==1) {
    MidiSend(noteOn2, 48, velocity);
    lman1[12] = 0;
    nyomva++;
  }
  else if (man1[12] == 1 and lman1[12]==0) {
    MidiSend(noteOff2, 48, velocity);
    lman1[12] = 1;
    nyomva--;
  }
  if (man1[13] == 0 and lman1[13]==1) {
    MidiSend(noteOn2, 59, velocity);
    lman1[13] = 0;
    nyomva++;
  }
  else if (man1[13] == 1 and lman1[13]==0) {
    MidiSend(noteOff2, 59, velocity);
    lman1[13] = 1;
    nyomva--;
  }
  if (man1[14] == 0 and lman1[14]==1) {
    MidiSend(noteOn2, 49, velocity);
    lman1[14] = 0;
    nyomva++;
  }
  else if (man1[14] == 1 and lman1[14]==0) {
    MidiSend(noteOff2, 49, velocity);
    lman1[14] = 1;
    nyomva--;
  }
  if (man1[15] == 0 and lman1[15]==1) {
    MidiSend(noteOn2, 58, velocity);
    lman1[15] = 0;
    nyomva++;
  }
  else if (man1[15] == 1 and lman1[15]==0) {
    MidiSend(noteOff2, 58, velocity);
    lman1[15] = 1;
    nyomva--;
  }
  if (man1[16] == 0 and lman1[16]==1) {
    MidiSend(noteOn2, 50, velocity);
    lman1[16] = 0;
    nyomva++;
  }
  else if (man1[16] == 1 and lman1[16]==0) {
    MidiSend(noteOff2, 50, velocity);
    lman1[16] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man1[17] == 0 and lman1[17]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman1[17] = 0;
    nyomva++;
  }
  else if (man1[17] == 1 and lman1[17]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman1[17] = 1;
    nyomva--;
  }
  */
  if (man1[18] == 0 and lman1[18]==1) {
    MidiSend(noteOn2, 51, velocity);
    lman1[18] = 0;
    nyomva++;
  }
  else if (man1[18] == 1 and lman1[18]==0) {
    MidiSend(noteOff2, 51, velocity);
    lman1[18] = 1;
    nyomva--;
  }
  if (man1[19] == 0 and lman1[19]==1) {
    MidiSend(noteOn2, 66, velocity);
    lman1[19] = 0;
    nyomva++;
  }
  else if (man1[19] == 1 and lman1[19]==0) {
    MidiSend(noteOff2, 66, velocity);
    lman1[19] = 1;
    nyomva--;
  }
  if (man1[20] == 0 and lman1[20]==1) {
    MidiSend(noteOn2, 52, velocity);
    lman1[20] = 0;
    nyomva++;
  }
  else if (man1[20] == 1 and lman1[20]==0) {
    MidiSend(noteOff2, 52, velocity);
    lman1[20] = 1;
    nyomva--;
  }
  if (man1[21] == 0 and lman1[21]==1) {
    MidiSend(noteOn2, 65, velocity);
    lman1[21] = 0;
    nyomva++;
  }
  else if (man1[21] == 1 and lman1[21]==0) {
    MidiSend(noteOff2, 65, velocity);
    lman1[21] = 1;
    nyomva--;
  }
  if (man1[22] == 0 and lman1[22]==1) {
    MidiSend(noteOn2, 53, velocity);
    lman1[22] = 0;
    nyomva++;
  }
  else if (man1[22] == 1 and lman1[22]==0) {
    MidiSend(noteOff2, 53, velocity);
    lman1[22] = 1;
    nyomva--;
  }
  if (man1[23] == 0 and lman1[23]==1) {
    MidiSend(noteOn2, 64, velocity);
    lman1[23] = 0;
    nyomva++;
  }
  else if (man1[23] == 1 and lman1[23]==0) {
    MidiSend(noteOff2, 64, velocity);
    lman1[23] = 1;
    nyomva--;
  }
  if (man1[24] == 0 and lman1[24]==1) {
    MidiSend(noteOn2, 54, velocity);
    lman1[24] = 0;
    nyomva++;
  }
  else if (man1[24] == 1 and lman1[24]==0) {
    MidiSend(noteOff2, 54, velocity);
    lman1[24] = 1;
    nyomva--;
  }
  if (man1[25] == 0 and lman1[25]==1) {
    MidiSend(noteOn2, 63, velocity);
    lman1[25] = 0;
    nyomva++;
  }
  else if (man1[25] == 1 and lman1[25]==0) {
    MidiSend(noteOff2, 63, velocity);
    lman1[25] = 1;
    nyomva--;
  }
  if (man1[26] == 0 and lman1[26]==1) {
    MidiSend(noteOn2, 55, velocity);
    lman1[26] = 0;
    nyomva++;
  }
  else if (man1[26] == 1 and lman1[26]==0) {
    MidiSend(noteOff2, 55, velocity);
    lman1[26] = 1;
    nyomva--;
  }
  if (man1[27] == 0 and lman1[27]==1) {
    MidiSend(noteOn2, 62, velocity);
    lman1[27] = 0;
    nyomva++;
  }
  else if (man1[27] == 1 and lman1[27]==0) {
    MidiSend(noteOff2, 62, velocity);
    lman1[27] = 1;
    nyomva--;
  }
  if (man1[28] == 0 and lman1[28]==1) {
    MidiSend(noteOn2, 56, velocity);
    lman1[28] = 0;
    nyomva++;
  }
  else if (man1[28] == 1 and lman1[28]==0) {
    MidiSend(noteOff2, 56, velocity);
    lman1[28] = 1;
    nyomva--;
  }
  if (man1[29] == 0 and lman1[29]==1) {
    MidiSend(noteOn2, 61, velocity);
    lman1[29] = 0;
    nyomva++;
  }
  else if (man1[29] == 1 and lman1[29]==0) {
    MidiSend(noteOff2, 61, velocity);
    lman1[29] = 1;
    nyomva--;
  }
  if (man1[30] == 0 and lman1[30]==1) {
    MidiSend(noteOn2, 57, velocity);
    lman1[30] = 0;
    nyomva++;
  }
  else if (man1[30] == 1 and lman1[30]==0) {
    MidiSend(noteOff2, 57, velocity);
    lman1[30] = 1;
    nyomva--;
  }
  if (man1[31] == 0 and lman1[31]==1) {
    MidiSend(noteOn2, 60, velocity);
    lman1[31] = 0;
    nyomva++;
  }
  else if (man1[31] == 1 and lman1[31]==0) {
    MidiSend(noteOff2, 60, velocity);
    lman1[31] = 1;
    nyomva--;
  }
  if (man1[32] == 0 and lman1[32]==1) {
    MidiSend(noteOn2, 72, velocity);
    lman1[32] = 0;
    nyomva++;
  }
  else if (man1[32] == 1 and lman1[32]==0) {
    MidiSend(noteOff2, 72, velocity);
    lman1[32] = 1;
    nyomva--;
  }
  if (man1[33] == 0 and lman1[33]==1) {
    MidiSend(noteOn2, 71, velocity);
    lman1[33] = 0;
    nyomva++;
  }
  else if (man1[33] == 1 and lman1[33]==0) {
    MidiSend(noteOff2, 71, velocity);
    lman1[33] = 1;
    nyomva--;
  }
  if (man1[34] == 0 and lman1[34]==1) {
    MidiSend(noteOn2, 73, velocity);
    lman1[34] = 0;
    nyomva++;
  }
  else if (man1[34] == 1 and lman1[34]==0) {
    MidiSend(noteOff2, 73, velocity);
    lman1[34] = 1;
    nyomva--;
  }
  if (man1[35] == 0 and lman1[35]==1) {
    MidiSend(noteOn2, 70, velocity);
    lman1[35] = 0;
    nyomva++;
  }
  else if (man1[35] == 1 and lman1[35]==0) {
    MidiSend(noteOff2, 70, velocity);
    lman1[35] = 1;
    nyomva--;
  }
  if (man1[36] == 0 and lman1[36]==1) {
    MidiSend(noteOn2, 74, velocity);
    lman1[36] = 0;
    nyomva++;
  }
  else if (man1[36] == 1 and lman1[36]==0) {
    MidiSend(noteOff2, 74, velocity);
    lman1[36] = 1;
    nyomva--;
  }
  if (man1[37] == 0 and lman1[37]==1) {
    MidiSend(noteOn2, 69, velocity);
    lman1[37] = 0;
    nyomva++;
  }
  else if (man1[37] == 1 and lman1[37]==0) {
    MidiSend(noteOff2, 69, velocity);
    lman1[37] = 1;
    nyomva--;
  }
  if (man1[38] == 0 and lman1[38]==1) {
    MidiSend(noteOn2, 75, velocity);
    lman1[38] = 0;
    nyomva++;
  }
  else if (man1[38] == 1 and lman1[38]==0) {
    MidiSend(noteOff2, 75, velocity);
    lman1[38] = 1;
    nyomva--;
  }
  if (man1[39] == 0 and lman1[39]==1) {
    MidiSend(noteOn2, 68, velocity);
    lman1[39] = 0;
    nyomva++;
  }
  else if (man1[39] == 1 and lman1[39]==0) {
    MidiSend(noteOff2, 68, velocity);
    lman1[39] = 1;
    nyomva--;
  }
  if (man1[40] == 0 and lman1[40]==1) {
    MidiSend(noteOn2, 76, velocity);
    lman1[40] = 0;
    nyomva++;
  }
  else if (man1[40] == 1 and lman1[40]==0) {
    MidiSend(noteOff2, 76, velocity);
    lman1[40] = 1;
    nyomva--;
  }
  if (man1[41] == 0 and lman1[41]==1) {
    MidiSend(noteOn2, 67, velocity);
    lman1[41] = 0;
    nyomva++;
  }
  else if (man1[41] == 1 and lman1[41]==0) {
    MidiSend(noteOff2, 67, velocity);
    lman1[41] = 1;
    nyomva--;
  }
  if (man1[42] == 0 and lman1[42]==1) {
    MidiSend(noteOn2, 77, velocity);
    lman1[42] = 0;
    nyomva++;
  }
  else if (man1[42] == 1 and lman1[42]==0) {
    MidiSend(noteOff2, 77, velocity);
    lman1[42] = 1;
    nyomva--;
  }
  /*NC
  if (man1[43] == 0 and lman1[43]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman1[43] = 0;
    nyomva++;
  }
  else if (man1[43] == 1 and lman1[43]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman1[43] = 1;
    nyomva--;
  }
  */
  if (man1[44] == 0 and lman1[44]==1) {
    MidiSend(noteOn2, 78, velocity);
    lman1[44] = 0;
    nyomva++;
  }
  else if (man1[44] == 1 and lman1[44]==0) {
    MidiSend(noteOff2, 78, velocity);
    lman1[44] = 1;
    nyomva--;
  }
  if (man1[45] == 0 and lman1[45]==1) {
    MidiSend(noteOn2, 89, velocity);
    lman1[45] = 0;
    nyomva++;
  }
  else if (man1[45] == 1 and lman1[45]==0) {
    MidiSend(noteOff2, 89, velocity);
    lman1[45] = 1;
    nyomva--;
  }
  if (man1[46] == 0 and lman1[46]==1) {
    MidiSend(noteOn2, 79, velocity);
    lman1[46] = 0;
    nyomva++;
  }
  else if (man1[46] == 1 and lman1[46]==0) {
    MidiSend(noteOff2, 79, velocity);
    lman1[46] = 1;
    nyomva--;
  }
  if (man1[47] == 0 and lman1[47]==1) {
    MidiSend(noteOn2, 88, velocity);
    lman1[47] = 0;
    nyomva++;
  }
  else if (man1[47] == 1 and lman1[47]==0) {
    MidiSend(noteOff2, 88, velocity);
    lman1[47] = 1;
    nyomva--;
  }
  if (man1[48] == 0 and lman1[48]==1) {
    MidiSend(noteOn2, 80, velocity);
    lman1[48] = 0;
    nyomva++;
  }
  else if (man1[48] == 1 and lman1[48]==0) {
    MidiSend(noteOff2, 80, velocity);
    lman1[48] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man1[49] == 0 and lman1[49]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman1[49] = 0;
    nyomva++;
  }
  else if (man1[49] == 1 and lman1[49]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman1[49] = 1;
    nyomva--;
  }
  */
  if (man1[50] == 0 and lman1[50]==1) {
    MidiSend(noteOn2, 81, velocity);
    lman1[50] = 0;
    nyomva++;
  }
  else if (man1[50] == 1 and lman1[50]==0) {
    MidiSend(noteOff2, 81, velocity);
    lman1[50] = 1;
    nyomva--;
  }
  if (man1[51] == 0 and lman1[51]==1) {
    MidiSend(noteOn2, 96, velocity);
    lman1[51] = 0;
    nyomva++;
  }
  else if (man1[51] == 1 and lman1[51]==0) {
    MidiSend(noteOff2, 96, velocity);
    lman1[51] = 1;
    nyomva--;
  }
  if (man1[52] == 0 and lman1[52]==1) {
    MidiSend(noteOn2, 82, velocity);
    lman1[52] = 0;
    nyomva++;
  }
  else if (man1[52] == 1 and lman1[52]==0) {
    MidiSend(noteOff2, 82, velocity);
    lman1[52] = 1;
    nyomva--;
  }
  if (man1[53] == 0 and lman1[53]==1) {
    MidiSend(noteOn2, 95, velocity);
    lman1[53] = 0;
    nyomva++;
  }
  else if (man1[53] == 1 and lman1[53]==0) {
    MidiSend(noteOff2, 95, velocity);
    lman1[53] = 1;
    nyomva--;
  }
  if (man1[54] == 0 and lman1[54]==1) {
    MidiSend(noteOn2, 83, velocity);
    lman1[54] = 0;
    nyomva++;
  }
  else if (man1[54] == 1 and lman1[54]==0) {
    MidiSend(noteOff2, 83, velocity);
    lman1[54] = 1;
    nyomva--;
  }
  if (man1[55] == 0 and lman1[55]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman1[55] = 0;
    nyomva++;
  }
  else if (man1[55] == 1 and lman1[55]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman1[55] = 1;
    nyomva--;
  }
  if (man1[56] == 0 and lman1[56]==1) {
    MidiSend(noteOn2, 84, velocity);
    lman1[56] = 0;
    nyomva++;
  }
  else if (man1[56] == 1 and lman1[56]==0) {
    MidiSend(noteOff2, 84, velocity);
    lman1[56] = 1;
    nyomva--;
  }
  if (man1[57] == 0 and lman1[57]==1) {
    MidiSend(noteOn2, 93, velocity);
    lman1[57] = 0;
    nyomva++;
  }
  else if (man1[57] == 1 and lman1[57]==0) {
    MidiSend(noteOff2, 93, velocity);
    lman1[57] = 1;
    nyomva--;
  }
  if (man1[58] == 0 and lman1[58]==1) {
    MidiSend(noteOn2, 85, velocity);
    lman1[58] = 0;
    nyomva++;
  }
  else if (man1[58] == 1 and lman1[58]==0) {
    MidiSend(noteOff2, 85, velocity);
    lman1[58] = 1;
    nyomva--;
  }
  if (man1[59] == 0 and lman1[59]==1) {
    MidiSend(noteOn2, 92, velocity);
    lman1[59] = 0;
    nyomva++;
  }
  else if (man1[59] == 1 and lman1[59]==0) {
    MidiSend(noteOff2, 92, velocity);
    lman1[59] = 1;
    nyomva--;
  }
  if (man1[60] == 0 and lman1[60]==1) {
    MidiSend(noteOn2, 86, velocity);
    lman1[60] = 0;
    nyomva++;
  }
  else if (man1[60] == 1 and lman1[60]==0) {
    MidiSend(noteOff2, 86, velocity);
    lman1[60] = 1;
    nyomva--;
  }
  if (man1[61] == 0 and lman1[61]==1) {
    MidiSend(noteOn2, 91, velocity);
    lman1[61] = 0;
    nyomva++;
  }
  else if (man1[61] == 1 and lman1[61]==0) {
    MidiSend(noteOff2, 91, velocity);
    lman1[61] = 1;
    nyomva--;
  }
  if (man1[62] == 0 and lman1[62]==1) {
    MidiSend(noteOn2, 87, velocity);
    lman1[62] = 0;
    nyomva++;
  }
  else if (man1[62] == 1 and lman1[62]==0) {
    MidiSend(noteOff2, 87, velocity);
    lman1[62] = 1;
    nyomva--;
  }
  if (man1[63] == 0 and lman1[63]==1) {
    MidiSend(noteOn2, 90, velocity);
    lman1[63] = 0;
    nyomva++;
  }
  else if (man1[63] == 1 and lman1[63]==0) {
    MidiSend(noteOff2, 90, velocity);
    lman1[63] = 1;
    nyomva--;
  }


  //write man2////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (man2[0] == 0 and lman2[0]==1) {
    MidiSend(noteOn2, 42, velocity);
    lman2[0] = 0;
    nyomva++;
  }
  else if (man2[0] == 1 and lman2[0]==0) {
    MidiSend(noteOff2, 42, velocity);
    lman2[0] = 1;
    nyomva--;
  }
  if (man2[1] == 0 and lman2[1]==1) {
    MidiSend(noteOn2, 41, velocity);
    lman2[1] = 0;
    nyomva++;
  }
  else if (man2[1] == 1 and lman2[1]==0) {
    MidiSend(noteOff2, 41, velocity);
    lman2[1] = 1;
    nyomva--;
  }
  if (man2[2] == 0 and lman2[2]==1) {
    MidiSend(noteOn2, 43, velocity);
    lman2[2] = 0;
    nyomva++;
  }
  else if (man2[2] == 1 and lman2[2]==0) {
    MidiSend(noteOff2, 43, velocity);
    lman2[2] = 1;
    nyomva--;
  }
  if (man2[3] == 0 and lman2[3]==1) {
    MidiSend(noteOn2, 40, velocity);
    lman2[3] = 0;
    nyomva++;
  }
  else if (man2[3] == 1 and lman2[3]==0) {
    MidiSend(noteOff2, 40, velocity);
    lman2[3] = 1;
    nyomva--;
  }
  if (man2[4] == 0 and lman2[4]==1) {
    MidiSend(noteOn2, 44, velocity);
    lman2[4] = 0;
    nyomva++;
  }
  else if (man2[4] == 1 and lman2[4]==0) {
    MidiSend(noteOff2, 44, velocity);
    lman2[4] = 1;
    nyomva--;
  }
  if (man2[5] == 0 and lman2[5]==1) {
    MidiSend(noteOn2, 39, velocity);
    lman2[5] = 0;
    nyomva++;
  }
  else if (man2[5] == 1 and lman2[5]==0) {
    MidiSend(noteOff2, 39, velocity);
    lman2[5] = 1;
    nyomva--;
  }
  if (man2[6] == 0 and lman2[6]==1) {
    MidiSend(noteOn2, 45, velocity);
    lman2[6] = 0;
    nyomva++;
  }
  else if (man2[6] == 1 and lman2[6]==0) {
    MidiSend(noteOff2, 45, velocity);
    lman2[6] = 1;
    nyomva--;
  }
  if (man2[7] == 0 and lman2[7]==1) {
    MidiSend(noteOn2, 38, velocity);
    lman2[7] = 0;
    nyomva++;
  }
  else if (man2[7] == 1 and lman2[7]==0) {
    MidiSend(noteOff2, 38, velocity);
    lman2[7] = 1;
    nyomva--;
  }
  if (man2[8] == 0 and lman2[8]==1) {
    MidiSend(noteOn2, 46, velocity);
    lman2[8] = 0;
    nyomva++;
  }
  else if (man2[8] == 1 and lman2[8]==0) {
    MidiSend(noteOff2, 46, velocity);
    lman2[8] = 1;
    nyomva--;
  }
  if (man2[9] == 0 and lman2[9]==1) {
    MidiSend(noteOn2, 37, velocity);
    lman2[9] = 0;
    nyomva++;
  }
  else if (man2[9] == 1 and lman2[9]==0) {
    MidiSend(noteOff2, 37, velocity);
    lman2[9] = 1;
    nyomva--;
  }
  if (man2[10] == 0 and lman2[10]==1) {
    MidiSend(noteOn2, 47, velocity);
    lman2[10] = 0;
    nyomva++;
  }
  else if (man2[10] == 1 and lman2[10]==0) {
    MidiSend(noteOff2, 47, velocity);
    lman2[10] = 1;
    nyomva--;
  }
  if (man2[11] == 0 and lman2[11]==1) {
    MidiSend(noteOn2, 36, velocity);
    lman2[11] = 0;
    nyomva++;
  }
  else if (man2[11] == 1 and lman2[11]==0) {
    MidiSend(noteOff2, 36, velocity);
    lman2[11] = 1;
    nyomva--;
  }
  if (man2[12] == 0 and lman2[12]==1) {
    MidiSend(noteOn2, 48, velocity);
    lman2[12] = 0;
    nyomva++;
  }
  else if (man2[12] == 1 and lman2[12]==0) {
    MidiSend(noteOff2, 48, velocity);
    lman2[12] = 1;
    nyomva--;
  }
  if (man2[13] == 0 and lman2[13]==1) {
    MidiSend(noteOn2, 59, velocity);
    lman2[13] = 0;
    nyomva++;
  }
  else if (man2[13] == 1 and lman2[13]==0) {
    MidiSend(noteOff2, 59, velocity);
    lman2[13] = 1;
    nyomva--;
  }
  if (man2[14] == 0 and lman2[14]==1) {
    MidiSend(noteOn2, 49, velocity);
    lman2[14] = 0;
    nyomva++;
  }
  else if (man2[14] == 1 and lman2[14]==0) {
    MidiSend(noteOff2, 49, velocity);
    lman2[14] = 1;
    nyomva--;
  }
  if (man2[15] == 0 and lman2[15]==1) {
    MidiSend(noteOn2, 58, velocity);
    lman2[15] = 0;
    nyomva++;
  }
  else if (man2[15] == 1 and lman2[15]==0) {
    MidiSend(noteOff2, 58, velocity);
    lman2[15] = 1;
    nyomva--;
  }
  if (man2[16] == 0 and lman2[16]==1) {
    MidiSend(noteOn2, 50, velocity);
    lman2[16] = 0;
    nyomva++;
  }
  else if (man2[16] == 1 and lman2[16]==0) {
    MidiSend(noteOff2, 50, velocity);
    lman2[16] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man2[17] == 0 and lman2[17]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman2[17] = 0;
    nyomva++;
  }
  else if (man2[17] == 1 and lman2[17]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman2[17] = 1;
    nyomva--;
  }
  */
  if (man2[18] == 0 and lman2[18]==1) {
    MidiSend(noteOn2, 51, velocity);
    lman2[18] = 0;
    nyomva++;
  }
  else if (man2[18] == 1 and lman2[18]==0) {
    MidiSend(noteOff2, 51, velocity);
    lman2[18] = 1;
    nyomva--;
  }
  if (man2[19] == 0 and lman2[19]==1) {
    MidiSend(noteOn2, 66, velocity);
    lman2[19] = 0;
    nyomva++;
  }
  else if (man2[19] == 1 and lman2[19]==0) {
    MidiSend(noteOff2, 66, velocity);
    lman2[19] = 1;
    nyomva--;
  }
  if (man2[20] == 0 and lman2[20]==1) {
    MidiSend(noteOn2, 52, velocity);
    lman2[20] = 0;
    nyomva++;
  }
  else if (man2[20] == 1 and lman2[20]==0) {
    MidiSend(noteOff2, 52, velocity);
    lman2[20] = 1;
    nyomva--;
  }
  if (man2[21] == 0 and lman2[21]==1) {
    MidiSend(noteOn2, 65, velocity);
    lman2[21] = 0;
    nyomva++;
  }
  else if (man2[21] == 1 and lman2[21]==0) {
    MidiSend(noteOff2, 65, velocity);
    lman2[21] = 1;
    nyomva--;
  }
  if (man2[22] == 0 and lman2[22]==1) {
    MidiSend(noteOn2, 53, velocity);
    lman2[22] = 0;
    nyomva++;
  }
  else if (man2[22] == 1 and lman2[22]==0) {
    MidiSend(noteOff2, 53, velocity);
    lman2[22] = 1;
    nyomva--;
  }
  if (man2[23] == 0 and lman2[23]==1) {
    MidiSend(noteOn2, 64, velocity);
    lman2[23] = 0;
    nyomva++;
  }
  else if (man2[23] == 1 and lman2[23]==0) {
    MidiSend(noteOff2, 64, velocity);
    lman2[23] = 1;
    nyomva--;
  }
  if (man2[24] == 0 and lman2[24]==1) {
    MidiSend(noteOn2, 54, velocity);
    lman2[24] = 0;
    nyomva++;
  }
  else if (man2[24] == 1 and lman2[24]==0) {
    MidiSend(noteOff2, 54, velocity);
    lman2[24] = 1;
    nyomva--;
  }
  if (man2[25] == 0 and lman2[25]==1) {
    MidiSend(noteOn2, 63, velocity);
    lman2[25] = 0;
    nyomva++;
  }
  else if (man2[25] == 1 and lman2[25]==0) {
    MidiSend(noteOff2, 63, velocity);
    lman2[25] = 1;
    nyomva--;
  }
  if (man2[26] == 0 and lman2[26]==1) {
    MidiSend(noteOn2, 55, velocity);
    lman2[26] = 0;
    nyomva++;
  }
  else if (man2[26] == 1 and lman2[26]==0) {
    MidiSend(noteOff2, 55, velocity);
    lman2[26] = 1;
    nyomva--;
  }
  if (man2[27] == 0 and lman2[27]==1) {
    MidiSend(noteOn2, 62, velocity);
    lman2[27] = 0;
    nyomva++;
  }
  else if (man2[27] == 1 and lman2[27]==0) {
    MidiSend(noteOff2, 62, velocity);
    lman2[27] = 1;
    nyomva--;
  }
  if (man2[28] == 0 and lman2[28]==1) {
    MidiSend(noteOn2, 56, velocity);
    lman2[28] = 0;
    nyomva++;
  }
  else if (man2[28] == 1 and lman2[28]==0) {
    MidiSend(noteOff2, 56, velocity);
    lman2[28] = 1;
    nyomva--;
  }
  if (man2[29] == 0 and lman2[29]==1) {
    MidiSend(noteOn2, 61, velocity);
    lman2[29] = 0;
    nyomva++;
  }
  else if (man2[29] == 1 and lman2[29]==0) {
    MidiSend(noteOff2, 61, velocity);
    lman2[29] = 1;
    nyomva--;
  }
  if (man2[30] == 0 and lman2[30]==1) {
    MidiSend(noteOn2, 57, velocity);
    lman2[30] = 0;
    nyomva++;
  }
  else if (man2[30] == 1 and lman2[30]==0) {
    MidiSend(noteOff2, 57, velocity);
    lman2[30] = 1;
    nyomva--;
  }
  if (man2[31] == 0 and lman2[31]==1) {
    MidiSend(noteOn2, 60, velocity);
    lman2[31] = 0;
    nyomva++;
  }
  else if (man2[31] == 1 and lman2[31]==0) {
    MidiSend(noteOff2, 60, velocity);
    lman2[31] = 1;
    nyomva--;
  }
  if (man2[32] == 0 and lman2[32]==1) {
    MidiSend(noteOn2, 72, velocity);
    lman2[32] = 0;
    nyomva++;
  }
  else if (man2[32] == 1 and lman2[32]==0) {
    MidiSend(noteOff2, 72, velocity);
    lman2[32] = 1;
    nyomva--;
  }
  if (man2[33] == 0 and lman2[33]==1) {
    MidiSend(noteOn2, 71, velocity);
    lman2[33] = 0;
    nyomva++;
  }
  else if (man2[33] == 1 and lman2[33]==0) {
    MidiSend(noteOff2, 71, velocity);
    lman2[33] = 1;
    nyomva--;
  }
  if (man2[34] == 0 and lman2[34]==1) {
    MidiSend(noteOn2, 73, velocity);
    lman2[34] = 0;
    nyomva++;
  }
  else if (man2[34] == 1 and lman2[34]==0) {
    MidiSend(noteOff2, 73, velocity);
    lman2[34] = 1;
    nyomva--;
  }
  if (man2[35] == 0 and lman2[35]==1) {
    MidiSend(noteOn2, 70, velocity);
    lman2[35] = 0;
    nyomva++;
  }
  else if (man2[35] == 1 and lman2[35]==0) {
    MidiSend(noteOff2, 70, velocity);
    lman2[35] = 1;
    nyomva--;
  }
  if (man2[36] == 0 and lman2[36]==1) {
    MidiSend(noteOn2, 74, velocity);
    lman2[36] = 0;
    nyomva++;
  }
  else if (man2[36] == 1 and lman2[36]==0) {
    MidiSend(noteOff2, 74, velocity);
    lman2[36] = 1;
    nyomva--;
  }
  if (man2[37] == 0 and lman2[37]==1) {
    MidiSend(noteOn2, 69, velocity);
    lman2[37] = 0;
    nyomva++;
  }
  else if (man2[37] == 1 and lman2[37]==0) {
    MidiSend(noteOff2, 69, velocity);
    lman2[37] = 1;
    nyomva--;
  }
  if (man2[38] == 0 and lman2[38]==1) {
    MidiSend(noteOn2, 75, velocity);
    lman2[38] = 0;
    nyomva++;
  }
  else if (man2[38] == 1 and lman2[38]==0) {
    MidiSend(noteOff2, 75, velocity);
    lman2[38] = 1;
    nyomva--;
  }
  if (man2[39] == 0 and lman2[39]==1) {
    MidiSend(noteOn2, 68, velocity);
    lman2[39] = 0;
    nyomva++;
  }
  else if (man2[39] == 1 and lman2[39]==0) {
    MidiSend(noteOff2, 68, velocity);
    lman2[39] = 1;
    nyomva--;
  }
  if (man2[40] == 0 and lman2[40]==1) {
    MidiSend(noteOn2, 76, velocity);
    lman2[40] = 0;
    nyomva++;
  }
  else if (man2[40] == 1 and lman2[40]==0) {
    MidiSend(noteOff2, 76, velocity);
    lman2[40] = 1;
    nyomva--;
  }
  if (man2[41] == 0 and lman2[41]==1) {
    MidiSend(noteOn2, 67, velocity);
    lman2[41] = 0;
    nyomva++;
  }
  else if (man2[41] == 1 and lman2[41]==0) {
    MidiSend(noteOff2, 67, velocity);
    lman2[41] = 1;
    nyomva--;
  }
  if (man2[42] == 0 and lman2[42]==1) {
    MidiSend(noteOn2, 77, velocity);
    lman2[42] = 0;
    nyomva++;
  }
  else if (man2[42] == 1 and lman2[42]==0) {
    MidiSend(noteOff2, 77, velocity);
    lman2[42] = 1;
    nyomva--;
  }
  /*NC
  if (man2[43] == 0 and lman2[43]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman2[43] = 0;
    nyomva++;
  }
  else if (man2[43] == 1 and lman2[43]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman2[43] = 1;
    nyomva--;
  }
  */
  if (man2[44] == 0 and lman2[44]==1) {
    MidiSend(noteOn2, 78, velocity);
    lman2[44] = 0;
    nyomva++;
  }
  else if (man2[44] == 1 and lman2[44]==0) {
    MidiSend(noteOff2, 78, velocity);
    lman2[44] = 1;
    nyomva--;
  }
  if (man2[45] == 0 and lman2[45]==1) {
    MidiSend(noteOn2, 89, velocity);
    lman2[45] = 0;
    nyomva++;
  }
  else if (man2[45] == 1 and lman2[45]==0) {
    MidiSend(noteOff2, 89, velocity);
    lman2[45] = 1;
    nyomva--;
  }
  if (man2[46] == 0 and lman2[46]==1) {
    MidiSend(noteOn2, 79, velocity);
    lman2[46] = 0;
    nyomva++;
  }
  else if (man2[46] == 1 and lman2[46]==0) {
    MidiSend(noteOff2, 79, velocity);
    lman2[46] = 1;
    nyomva--;
  }
  if (man2[47] == 0 and lman2[47]==1) {
    MidiSend(noteOn2, 88, velocity);
    lman2[47] = 0;
    nyomva++;
  }
  else if (man2[47] == 1 and lman2[47]==0) {
    MidiSend(noteOff2, 88, velocity);
    lman2[47] = 1;
    nyomva--;
  }
  if (man2[48] == 0 and lman2[48]==1) {
    MidiSend(noteOn2, 80, velocity);
    lman2[48] = 0;
    nyomva++;
  }
  else if (man2[48] == 1 and lman2[48]==0) {
    MidiSend(noteOff2, 80, velocity);
    lman2[48] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man2[49] == 0 and lman2[49]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman2[49] = 0;
    nyomva++;
  }
  else if (man2[49] == 1 and lman2[49]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman2[49] = 1;
    nyomva--;
  }
  */
  if (man2[50] == 0 and lman2[50]==1) {
    MidiSend(noteOn2, 81, velocity);
    lman2[50] = 0;
    nyomva++;
  }
  else if (man2[50] == 1 and lman2[50]==0) {
    MidiSend(noteOff2, 81, velocity);
    lman2[50] = 1;
    nyomva--;
  }
  if (man2[51] == 0 and lman2[51]==1) {
    MidiSend(noteOn2, 96, velocity);
    lman2[51] = 0;
    nyomva++;
  }
  else if (man2[51] == 1 and lman2[51]==0) {
    MidiSend(noteOff2, 96, velocity);
    lman2[51] = 1;
    nyomva--;
  }
  if (man2[52] == 0 and lman2[52]==1) {
    MidiSend(noteOn2, 82, velocity);
    lman2[52] = 0;
    nyomva++;
  }
  else if (man2[52] == 1 and lman2[52]==0) {
    MidiSend(noteOff2, 82, velocity);
    lman2[52] = 1;
    nyomva--;
  }
  if (man2[53] == 0 and lman2[53]==1) {
    MidiSend(noteOn2, 95, velocity);
    lman2[53] = 0;
    nyomva++;
  }
  else if (man2[53] == 1 and lman2[53]==0) {
    MidiSend(noteOff2, 95, velocity);
    lman2[53] = 1;
    nyomva--;
  }
  if (man2[54] == 0 and lman2[54]==1) {
    MidiSend(noteOn2, 83, velocity);
    lman2[54] = 0;
    nyomva++;
  }
  else if (man2[54] == 1 and lman2[54]==0) {
    MidiSend(noteOff2, 83, velocity);
    lman2[54] = 1;
    nyomva--;
  }
  if (man2[55] == 0 and lman2[55]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman2[55] = 0;
    nyomva++;
  }
  else if (man2[55] == 1 and lman2[55]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman2[55] = 1;
    nyomva--;
  }
  if (man2[56] == 0 and lman2[56]==1) {
    MidiSend(noteOn2, 84, velocity);
    lman2[56] = 0;
    nyomva++;
  }
  else if (man2[56] == 1 and lman2[56]==0) {
    MidiSend(noteOff2, 84, velocity);
    lman2[56] = 1;
    nyomva--;
  }
  if (man2[57] == 0 and lman2[57]==1) {
    MidiSend(noteOn2, 93, velocity);
    lman2[57] = 0;
    nyomva++;
  }
  else if (man2[57] == 1 and lman2[57]==0) {
    MidiSend(noteOff2, 93, velocity);
    lman2[57] = 1;
    nyomva--;
  }
  if (man2[58] == 0 and lman2[58]==1) {
    MidiSend(noteOn2, 85, velocity);
    lman2[58] = 0;
    nyomva++;
  }
  else if (man2[58] == 1 and lman2[58]==0) {
    MidiSend(noteOff2, 85, velocity);
    lman2[58] = 1;
    nyomva--;
  }
  if (man2[59] == 0 and lman2[59]==1) {
    MidiSend(noteOn2, 92, velocity);
    lman2[59] = 0;
    nyomva++;
  }
  else if (man2[59] == 1 and lman2[59]==0) {
    MidiSend(noteOff2, 92, velocity);
    lman2[59] = 1;
    nyomva--;
  }
  if (man2[60] == 0 and lman2[60]==1) {
    MidiSend(noteOn2, 86, velocity);
    lman2[60] = 0;
    nyomva++;
  }
  else if (man2[60] == 1 and lman2[60]==0) {
    MidiSend(noteOff2, 86, velocity);
    lman2[60] = 1;
    nyomva--;
  }
  if (man2[61] == 0 and lman2[61]==1) {
    MidiSend(noteOn2, 91, velocity);
    lman2[61] = 0;
    nyomva++;
  }
  else if (man2[61] == 1 and lman2[61]==0) {
    MidiSend(noteOff2, 91, velocity);
    lman2[61] = 1;
    nyomva--;
  }
  if (man2[62] == 0 and lman2[62]==1) {
    MidiSend(noteOn2, 87, velocity);
    lman2[62] = 0;
    nyomva++;
  }
  else if (man2[62] == 1 and lman2[62]==0) {
    MidiSend(noteOff2, 87, velocity);
    lman2[62] = 1;
    nyomva--;
  }
  if (man2[63] == 0 and lman2[63]==1) {
    MidiSend(noteOn2, 90, velocity);
    lman2[63] = 0;
    nyomva++;
  }
  else if (man2[63] == 1 and lman2[63]==0) {
    MidiSend(noteOff2, 90, velocity);
    lman2[63] = 1;
    nyomva--;
  }


  //write man3////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (man3[0] == 0 and lman3[0]==1) {
    MidiSend(noteOn2, 42, velocity);
    lman3[0] = 0;
    nyomva++;
  }
  else if (man3[0] == 1 and lman3[0]==0) {
    MidiSend(noteOff2, 42, velocity);
    lman3[0] = 1;
    nyomva--;
  }
  if (man3[1] == 0 and lman3[1]==1) {
    MidiSend(noteOn2, 41, velocity);
    lman3[1] = 0;
    nyomva++;
  }
  else if (man3[1] == 1 and lman3[1]==0) {
    MidiSend(noteOff2, 41, velocity);
    lman3[1] = 1;
    nyomva--;
  }
  if (man3[2] == 0 and lman3[2]==1) {
    MidiSend(noteOn2, 43, velocity);
    lman3[2] = 0;
    nyomva++;
  }
  else if (man3[2] == 1 and lman3[2]==0) {
    MidiSend(noteOff2, 43, velocity);
    lman3[2] = 1;
    nyomva--;
  }
  if (man3[3] == 0 and lman3[3]==1) {
    MidiSend(noteOn2, 40, velocity);
    lman3[3] = 0;
    nyomva++;
  }
  else if (man3[3] == 1 and lman3[3]==0) {
    MidiSend(noteOff2, 40, velocity);
    lman3[3] = 1;
    nyomva--;
  }
  if (man3[4] == 0 and lman3[4]==1) {
    MidiSend(noteOn2, 44, velocity);
    lman3[4] = 0;
    nyomva++;
  }
  else if (man3[4] == 1 and lman3[4]==0) {
    MidiSend(noteOff2, 44, velocity);
    lman3[4] = 1;
    nyomva--;
  }
  if (man3[5] == 0 and lman3[5]==1) {
    MidiSend(noteOn2, 39, velocity);
    lman3[5] = 0;
    nyomva++;
  }
  else if (man3[5] == 1 and lman3[5]==0) {
    MidiSend(noteOff2, 39, velocity);
    lman3[5] = 1;
    nyomva--;
  }
  if (man3[6] == 0 and lman3[6]==1) {
    MidiSend(noteOn2, 45, velocity);
    lman3[6] = 0;
    nyomva++;
  }
  else if (man3[6] == 1 and lman3[6]==0) {
    MidiSend(noteOff2, 45, velocity);
    lman3[6] = 1;
    nyomva--;
  }
  if (man3[7] == 0 and lman3[7]==1) {
    MidiSend(noteOn2, 38, velocity);
    lman3[7] = 0;
    nyomva++;
  }
  else if (man3[7] == 1 and lman3[7]==0) {
    MidiSend(noteOff2, 38, velocity);
    lman3[7] = 1;
    nyomva--;
  }
  if (man3[8] == 0 and lman3[8]==1) {
    MidiSend(noteOn2, 46, velocity);
    lman3[8] = 0;
    nyomva++;
  }
  else if (man3[8] == 1 and lman3[8]==0) {
    MidiSend(noteOff2, 46, velocity);
    lman3[8] = 1;
    nyomva--;
  }
  if (man3[9] == 0 and lman3[9]==1) {
    MidiSend(noteOn2, 37, velocity);
    lman3[9] = 0;
    nyomva++;
  }
  else if (man3[9] == 1 and lman3[9]==0) {
    MidiSend(noteOff2, 37, velocity);
    lman3[9] = 1;
    nyomva--;
  }
  if (man3[10] == 0 and lman3[10]==1) {
    MidiSend(noteOn2, 47, velocity);
    lman3[10] = 0;
    nyomva++;
  }
  else if (man3[10] == 1 and lman3[10]==0) {
    MidiSend(noteOff2, 47, velocity);
    lman3[10] = 1;
    nyomva--;
  }
  if (man3[11] == 0 and lman3[11]==1) {
    MidiSend(noteOn2, 36, velocity);
    lman3[11] = 0;
    nyomva++;
  }
  else if (man3[11] == 1 and lman3[11]==0) {
    MidiSend(noteOff2, 36, velocity);
    lman3[11] = 1;
    nyomva--;
  }
  if (man3[12] == 0 and lman3[12]==1) {
    MidiSend(noteOn2, 48, velocity);
    lman3[12] = 0;
    nyomva++;
  }
  else if (man3[12] == 1 and lman3[12]==0) {
    MidiSend(noteOff2, 48, velocity);
    lman3[12] = 1;
    nyomva--;
  }
  if (man3[13] == 0 and lman3[13]==1) {
    MidiSend(noteOn2, 59, velocity);
    lman3[13] = 0;
    nyomva++;
  }
  else if (man3[13] == 1 and lman3[13]==0) {
    MidiSend(noteOff2, 59, velocity);
    lman3[13] = 1;
    nyomva--;
  }
  if (man3[14] == 0 and lman3[14]==1) {
    MidiSend(noteOn2, 49, velocity);
    lman3[14] = 0;
    nyomva++;
  }
  else if (man3[14] == 1 and lman3[14]==0) {
    MidiSend(noteOff2, 49, velocity);
    lman3[14] = 1;
    nyomva--;
  }
  if (man3[15] == 0 and lman3[15]==1) {
    MidiSend(noteOn2, 58, velocity);
    lman3[15] = 0;
    nyomva++;
  }
  else if (man3[15] == 1 and lman3[15]==0) {
    MidiSend(noteOff2, 58, velocity);
    lman3[15] = 1;
    nyomva--;
  }
  if (man3[16] == 0 and lman3[16]==1) {
    MidiSend(noteOn2, 50, velocity);
    lman3[16] = 0;
    nyomva++;
  }
  else if (man3[16] == 1 and lman3[16]==0) {
    MidiSend(noteOff2, 50, velocity);
    lman3[16] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man3[17] == 0 and lman3[17]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman3[17] = 0;
    nyomva++;
  }
  else if (man3[17] == 1 and lman3[17]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman3[17] = 1;
    nyomva--;
  }
  */
  if (man3[18] == 0 and lman3[18]==1) {
    MidiSend(noteOn2, 51, velocity);
    lman3[18] = 0;
    nyomva++;
  }
  else if (man3[18] == 1 and lman3[18]==0) {
    MidiSend(noteOff2, 51, velocity);
    lman3[18] = 1;
    nyomva--;
  }
  if (man3[19] == 0 and lman3[19]==1) {
    MidiSend(noteOn2, 66, velocity);
    lman3[19] = 0;
    nyomva++;
  }
  else if (man3[19] == 1 and lman3[19]==0) {
    MidiSend(noteOff2, 66, velocity);
    lman3[19] = 1;
    nyomva--;
  }
  if (man3[20] == 0 and lman3[20]==1) {
    MidiSend(noteOn2, 52, velocity);
    lman3[20] = 0;
    nyomva++;
  }
  else if (man3[20] == 1 and lman3[20]==0) {
    MidiSend(noteOff2, 52, velocity);
    lman3[20] = 1;
    nyomva--;
  }
  if (man3[21] == 0 and lman3[21]==1) {
    MidiSend(noteOn2, 65, velocity);
    lman3[21] = 0;
    nyomva++;
  }
  else if (man3[21] == 1 and lman3[21]==0) {
    MidiSend(noteOff2, 65, velocity);
    lman3[21] = 1;
    nyomva--;
  }
  if (man3[22] == 0 and lman3[22]==1) {
    MidiSend(noteOn2, 53, velocity);
    lman3[22] = 0;
    nyomva++;
  }
  else if (man3[22] == 1 and lman3[22]==0) {
    MidiSend(noteOff2, 53, velocity);
    lman3[22] = 1;
    nyomva--;
  }
  if (man3[23] == 0 and lman3[23]==1) {
    MidiSend(noteOn2, 64, velocity);
    lman3[23] = 0;
    nyomva++;
  }
  else if (man3[23] == 1 and lman3[23]==0) {
    MidiSend(noteOff2, 64, velocity);
    lman3[23] = 1;
    nyomva--;
  }
  if (man3[24] == 0 and lman3[24]==1) {
    MidiSend(noteOn2, 54, velocity);
    lman3[24] = 0;
    nyomva++;
  }
  else if (man3[24] == 1 and lman3[24]==0) {
    MidiSend(noteOff2, 54, velocity);
    lman3[24] = 1;
    nyomva--;
  }
  if (man3[25] == 0 and lman3[25]==1) {
    MidiSend(noteOn2, 63, velocity);
    lman3[25] = 0;
    nyomva++;
  }
  else if (man3[25] == 1 and lman3[25]==0) {
    MidiSend(noteOff2, 63, velocity);
    lman3[25] = 1;
    nyomva--;
  }
  if (man3[26] == 0 and lman3[26]==1) {
    MidiSend(noteOn2, 55, velocity);
    lman3[26] = 0;
    nyomva++;
  }
  else if (man3[26] == 1 and lman3[26]==0) {
    MidiSend(noteOff2, 55, velocity);
    lman3[26] = 1;
    nyomva--;
  }
  if (man3[27] == 0 and lman3[27]==1) {
    MidiSend(noteOn2, 62, velocity);
    lman3[27] = 0;
    nyomva++;
  }
  else if (man3[27] == 1 and lman3[27]==0) {
    MidiSend(noteOff2, 62, velocity);
    lman3[27] = 1;
    nyomva--;
  }
  if (man3[28] == 0 and lman3[28]==1) {
    MidiSend(noteOn2, 56, velocity);
    lman3[28] = 0;
    nyomva++;
  }
  else if (man3[28] == 1 and lman3[28]==0) {
    MidiSend(noteOff2, 56, velocity);
    lman3[28] = 1;
    nyomva--;
  }
  if (man3[29] == 0 and lman3[29]==1) {
    MidiSend(noteOn2, 61, velocity);
    lman3[29] = 0;
    nyomva++;
  }
  else if (man3[29] == 1 and lman3[29]==0) {
    MidiSend(noteOff2, 61, velocity);
    lman3[29] = 1;
    nyomva--;
  }
  if (man3[30] == 0 and lman3[30]==1) {
    MidiSend(noteOn2, 57, velocity);
    lman3[30] = 0;
    nyomva++;
  }
  else if (man3[30] == 1 and lman3[30]==0) {
    MidiSend(noteOff2, 57, velocity);
    lman3[30] = 1;
    nyomva--;
  }
  if (man3[31] == 0 and lman3[31]==1) {
    MidiSend(noteOn2, 60, velocity);
    lman3[31] = 0;
    nyomva++;
  }
  else if (man3[31] == 1 and lman3[31]==0) {
    MidiSend(noteOff2, 60, velocity);
    lman3[31] = 1;
    nyomva--;
  }
  if (man3[32] == 0 and lman3[32]==1) {
    MidiSend(noteOn2, 72, velocity);
    lman3[32] = 0;
    nyomva++;
  }
  else if (man3[32] == 1 and lman3[32]==0) {
    MidiSend(noteOff2, 72, velocity);
    lman3[32] = 1;
    nyomva--;
  }
  if (man3[33] == 0 and lman3[33]==1) {
    MidiSend(noteOn2, 71, velocity);
    lman3[33] = 0;
    nyomva++;
  }
  else if (man3[33] == 1 and lman3[33]==0) {
    MidiSend(noteOff2, 71, velocity);
    lman3[33] = 1;
    nyomva--;
  }
  if (man3[34] == 0 and lman3[34]==1) {
    MidiSend(noteOn2, 73, velocity);
    lman3[34] = 0;
    nyomva++;
  }
  else if (man3[34] == 1 and lman3[34]==0) {
    MidiSend(noteOff2, 73, velocity);
    lman3[34] = 1;
    nyomva--;
  }
  if (man3[35] == 0 and lman3[35]==1) {
    MidiSend(noteOn2, 70, velocity);
    lman3[35] = 0;
    nyomva++;
  }
  else if (man3[35] == 1 and lman3[35]==0) {
    MidiSend(noteOff2, 70, velocity);
    lman3[35] = 1;
    nyomva--;
  }
  if (man3[36] == 0 and lman3[36]==1) {
    MidiSend(noteOn2, 74, velocity);
    lman3[36] = 0;
    nyomva++;
  }
  else if (man3[36] == 1 and lman3[36]==0) {
    MidiSend(noteOff2, 74, velocity);
    lman3[36] = 1;
    nyomva--;
  }
  if (man3[37] == 0 and lman3[37]==1) {
    MidiSend(noteOn2, 69, velocity);
    lman3[37] = 0;
    nyomva++;
  }
  else if (man3[37] == 1 and lman3[37]==0) {
    MidiSend(noteOff2, 69, velocity);
    lman3[37] = 1;
    nyomva--;
  }
  if (man3[38] == 0 and lman3[38]==1) {
    MidiSend(noteOn2, 75, velocity);
    lman3[38] = 0;
    nyomva++;
  }
  else if (man3[38] == 1 and lman3[38]==0) {
    MidiSend(noteOff2, 75, velocity);
    lman3[38] = 1;
    nyomva--;
  }
  if (man3[39] == 0 and lman3[39]==1) {
    MidiSend(noteOn2, 68, velocity);
    lman3[39] = 0;
    nyomva++;
  }
  else if (man3[39] == 1 and lman3[39]==0) {
    MidiSend(noteOff2, 68, velocity);
    lman3[39] = 1;
    nyomva--;
  }
  if (man3[40] == 0 and lman3[40]==1) {
    MidiSend(noteOn2, 76, velocity);
    lman3[40] = 0;
    nyomva++;
  }
  else if (man3[40] == 1 and lman3[40]==0) {
    MidiSend(noteOff2, 76, velocity);
    lman3[40] = 1;
    nyomva--;
  }
  if (man3[41] == 0 and lman3[41]==1) {
    MidiSend(noteOn2, 67, velocity);
    lman3[41] = 0;
    nyomva++;
  }
  else if (man3[41] == 1 and lman3[41]==0) {
    MidiSend(noteOff2, 67, velocity);
    lman3[41] = 1;
    nyomva--;
  }
  if (man3[42] == 0 and lman3[42]==1) {
    MidiSend(noteOn2, 77, velocity);
    lman3[42] = 0;
    nyomva++;
  }
  else if (man3[42] == 1 and lman3[42]==0) {
    MidiSend(noteOff2, 77, velocity);
    lman3[42] = 1;
    nyomva--;
  }
  /*NC
  if (man3[43] == 0 and lman3[43]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman3[43] = 0;
    nyomva++;
  }
  else if (man3[43] == 1 and lman3[43]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman3[43] = 1;
    nyomva--;
  }
  */
  if (man3[44] == 0 and lman3[44]==1) {
    MidiSend(noteOn2, 78, velocity);
    lman3[44] = 0;
    nyomva++;
  }
  else if (man3[44] == 1 and lman3[44]==0) {
    MidiSend(noteOff2, 78, velocity);
    lman3[44] = 1;
    nyomva--;
  }
  if (man3[45] == 0 and lman3[45]==1) {
    MidiSend(noteOn2, 89, velocity);
    lman3[45] = 0;
    nyomva++;
  }
  else if (man3[45] == 1 and lman3[45]==0) {
    MidiSend(noteOff2, 89, velocity);
    lman3[45] = 1;
    nyomva--;
  }
  if (man3[46] == 0 and lman3[46]==1) {
    MidiSend(noteOn2, 79, velocity);
    lman3[46] = 0;
    nyomva++;
  }
  else if (man3[46] == 1 and lman3[46]==0) {
    MidiSend(noteOff2, 79, velocity);
    lman3[46] = 1;
    nyomva--;
  }
  if (man3[47] == 0 and lman3[47]==1) {
    MidiSend(noteOn2, 88, velocity);
    lman3[47] = 0;
    nyomva++;
  }
  else if (man3[47] == 1 and lman3[47]==0) {
    MidiSend(noteOff2, 88, velocity);
    lman3[47] = 1;
    nyomva--;
  }
  if (man3[48] == 0 and lman3[48]==1) {
    MidiSend(noteOn2, 80, velocity);
    lman3[48] = 0;
    nyomva++;
  }
  else if (man3[48] == 1 and lman3[48]==0) {
    MidiSend(noteOff2, 80, velocity);
    lman3[48] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man3[49] == 0 and lman3[49]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman3[49] = 0;
    nyomva++;
  }
  else if (man3[49] == 1 and lman3[49]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman3[49] = 1;
    nyomva--;
  }
  */
  if (man3[50] == 0 and lman3[50]==1) {
    MidiSend(noteOn2, 81, velocity);
    lman3[50] = 0;
    nyomva++;
  }
  else if (man3[50] == 1 and lman3[50]==0) {
    MidiSend(noteOff2, 81, velocity);
    lman3[50] = 1;
    nyomva--;
  }
  if (man3[51] == 0 and lman3[51]==1) {
    MidiSend(noteOn2, 96, velocity);
    lman3[51] = 0;
    nyomva++;
  }
  else if (man3[51] == 1 and lman3[51]==0) {
    MidiSend(noteOff2, 96, velocity);
    lman3[51] = 1;
    nyomva--;
  }
  if (man3[52] == 0 and lman3[52]==1) {
    MidiSend(noteOn2, 82, velocity);
    lman3[52] = 0;
    nyomva++;
  }
  else if (man3[52] == 1 and lman3[52]==0) {
    MidiSend(noteOff2, 82, velocity);
    lman3[52] = 1;
    nyomva--;
  }
  if (man3[53] == 0 and lman3[53]==1) {
    MidiSend(noteOn2, 95, velocity);
    lman3[53] = 0;
    nyomva++;
  }
  else if (man3[53] == 1 and lman3[53]==0) {
    MidiSend(noteOff2, 95, velocity);
    lman3[53] = 1;
    nyomva--;
  }
  if (man3[54] == 0 and lman3[54]==1) {
    MidiSend(noteOn2, 83, velocity);
    lman3[54] = 0;
    nyomva++;
  }
  else if (man3[54] == 1 and lman3[54]==0) {
    MidiSend(noteOff2, 83, velocity);
    lman3[54] = 1;
    nyomva--;
  }
  if (man3[55] == 0 and lman3[55]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman3[55] = 0;
    nyomva++;
  }
  else if (man3[55] == 1 and lman3[55]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman3[55] = 1;
    nyomva--;
  }
  if (man3[56] == 0 and lman3[56]==1) {
    MidiSend(noteOn2, 84, velocity);
    lman3[56] = 0;
    nyomva++;
  }
  else if (man3[56] == 1 and lman3[56]==0) {
    MidiSend(noteOff2, 84, velocity);
    lman3[56] = 1;
    nyomva--;
  }
  if (man3[57] == 0 and lman3[57]==1) {
    MidiSend(noteOn2, 93, velocity);
    lman3[57] = 0;
    nyomva++;
  }
  else if (man3[57] == 1 and lman3[57]==0) {
    MidiSend(noteOff2, 93, velocity);
    lman3[57] = 1;
    nyomva--;
  }
  if (man3[58] == 0 and lman3[58]==1) {
    MidiSend(noteOn2, 85, velocity);
    lman3[58] = 0;
    nyomva++;
  }
  else if (man3[58] == 1 and lman3[58]==0) {
    MidiSend(noteOff2, 85, velocity);
    lman3[58] = 1;
    nyomva--;
  }
  if (man3[59] == 0 and lman3[59]==1) {
    MidiSend(noteOn2, 92, velocity);
    lman3[59] = 0;
    nyomva++;
  }
  else if (man3[59] == 1 and lman3[59]==0) {
    MidiSend(noteOff2, 92, velocity);
    lman3[59] = 1;
    nyomva--;
  }
  if (man3[60] == 0 and lman3[60]==1) {
    MidiSend(noteOn2, 86, velocity);
    lman3[60] = 0;
    nyomva++;
  }
  else if (man3[60] == 1 and lman3[60]==0) {
    MidiSend(noteOff2, 86, velocity);
    lman3[60] = 1;
    nyomva--;
  }
  if (man3[61] == 0 and lman3[61]==1) {
    MidiSend(noteOn2, 91, velocity);
    lman3[61] = 0;
    nyomva++;
  }
  else if (man3[61] == 1 and lman3[61]==0) {
    MidiSend(noteOff2, 91, velocity);
    lman3[61] = 1;
    nyomva--;
  }
  if (man3[62] == 0 and lman3[62]==1) {
    MidiSend(noteOn2, 87, velocity);
    lman3[62] = 0;
    nyomva++;
  }
  else if (man3[62] == 1 and lman3[62]==0) {
    MidiSend(noteOff2, 87, velocity);
    lman3[62] = 1;
    nyomva--;
  }
  if (man3[63] == 0 and lman3[63]==1) {
    MidiSend(noteOn2, 90, velocity);
    lman3[63] = 0;
    nyomva++;
  }
  else if (man3[63] == 1 and lman3[63]==0) {
    MidiSend(noteOff2, 90, velocity);
    lman3[63] = 1;
    nyomva--;
  }


  //write man4////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (man4[0] == 0 and lman4[0]==1) {
    MidiSend(noteOn2, 42, velocity);
    lman4[0] = 0;
    nyomva++;
  }
  else if (man4[0] == 1 and lman4[0]==0) {
    MidiSend(noteOff2, 42, velocity);
    lman4[0] = 1;
    nyomva--;
  }
  if (man4[1] == 0 and lman4[1]==1) {
    MidiSend(noteOn2, 41, velocity);
    lman4[1] = 0;
    nyomva++;
  }
  else if (man4[1] == 1 and lman4[1]==0) {
    MidiSend(noteOff2, 41, velocity);
    lman4[1] = 1;
    nyomva--;
  }
  if (man4[2] == 0 and lman4[2]==1) {
    MidiSend(noteOn2, 43, velocity);
    lman4[2] = 0;
    nyomva++;
  }
  else if (man4[2] == 1 and lman4[2]==0) {
    MidiSend(noteOff2, 43, velocity);
    lman4[2] = 1;
    nyomva--;
  }
  if (man4[3] == 0 and lman4[3]==1) {
    MidiSend(noteOn2, 40, velocity);
    lman4[3] = 0;
    nyomva++;
  }
  else if (man4[3] == 1 and lman4[3]==0) {
    MidiSend(noteOff2, 40, velocity);
    lman4[3] = 1;
    nyomva--;
  }
  if (man4[4] == 0 and lman4[4]==1) {
    MidiSend(noteOn2, 44, velocity);
    lman4[4] = 0;
    nyomva++;
  }
  else if (man4[4] == 1 and lman4[4]==0) {
    MidiSend(noteOff2, 44, velocity);
    lman4[4] = 1;
    nyomva--;
  }
  if (man4[5] == 0 and lman4[5]==1) {
    MidiSend(noteOn2, 39, velocity);
    lman4[5] = 0;
    nyomva++;
  }
  else if (man4[5] == 1 and lman4[5]==0) {
    MidiSend(noteOff2, 39, velocity);
    lman4[5] = 1;
    nyomva--;
  }
  if (man4[6] == 0 and lman4[6]==1) {
    MidiSend(noteOn2, 45, velocity);
    lman4[6] = 0;
    nyomva++;
  }
  else if (man4[6] == 1 and lman4[6]==0) {
    MidiSend(noteOff2, 45, velocity);
    lman4[6] = 1;
    nyomva--;
  }
  if (man4[7] == 0 and lman4[7]==1) {
    MidiSend(noteOn2, 38, velocity);
    lman4[7] = 0;
    nyomva++;
  }
  else if (man4[7] == 1 and lman4[7]==0) {
    MidiSend(noteOff2, 38, velocity);
    lman4[7] = 1;
    nyomva--;
  }
  if (man4[8] == 0 and lman4[8]==1) {
    MidiSend(noteOn2, 46, velocity);
    lman4[8] = 0;
    nyomva++;
  }
  else if (man4[8] == 1 and lman4[8]==0) {
    MidiSend(noteOff2, 46, velocity);
    lman4[8] = 1;
    nyomva--;
  }
  if (man4[9] == 0 and lman4[9]==1) {
    MidiSend(noteOn2, 37, velocity);
    lman4[9] = 0;
    nyomva++;
  }
  else if (man4[9] == 1 and lman4[9]==0) {
    MidiSend(noteOff2, 37, velocity);
    lman4[9] = 1;
    nyomva--;
  }
  if (man4[10] == 0 and lman4[10]==1) {
    MidiSend(noteOn2, 47, velocity);
    lman4[10] = 0;
    nyomva++;
  }
  else if (man4[10] == 1 and lman4[10]==0) {
    MidiSend(noteOff2, 47, velocity);
    lman4[10] = 1;
    nyomva--;
  }
  if (man4[11] == 0 and lman4[11]==1) {
    MidiSend(noteOn2, 36, velocity);
    lman4[11] = 0;
    nyomva++;
  }
  else if (man4[11] == 1 and lman4[11]==0) {
    MidiSend(noteOff2, 36, velocity);
    lman4[11] = 1;
    nyomva--;
  }
  if (man4[12] == 0 and lman4[12]==1) {
    MidiSend(noteOn2, 48, velocity);
    lman4[12] = 0;
    nyomva++;
  }
  else if (man4[12] == 1 and lman4[12]==0) {
    MidiSend(noteOff2, 48, velocity);
    lman4[12] = 1;
    nyomva--;
  }
  if (man4[13] == 0 and lman4[13]==1) {
    MidiSend(noteOn2, 59, velocity);
    lman4[13] = 0;
    nyomva++;
  }
  else if (man4[13] == 1 and lman4[13]==0) {
    MidiSend(noteOff2, 59, velocity);
    lman4[13] = 1;
    nyomva--;
  }
  if (man4[14] == 0 and lman4[14]==1) {
    MidiSend(noteOn2, 49, velocity);
    lman4[14] = 0;
    nyomva++;
  }
  else if (man4[14] == 1 and lman4[14]==0) {
    MidiSend(noteOff2, 49, velocity);
    lman4[14] = 1;
    nyomva--;
  }
  if (man4[15] == 0 and lman4[15]==1) {
    MidiSend(noteOn2, 58, velocity);
    lman4[15] = 0;
    nyomva++;
  }
  else if (man4[15] == 1 and lman4[15]==0) {
    MidiSend(noteOff2, 58, velocity);
    lman4[15] = 1;
    nyomva--;
  }
  if (man4[16] == 0 and lman4[16]==1) {
    MidiSend(noteOn2, 50, velocity);
    lman4[16] = 0;
    nyomva++;
  }
  else if (man4[16] == 1 and lman4[16]==0) {
    MidiSend(noteOff2, 50, velocity);
    lman4[16] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man4[17] == 0 and lman4[17]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman4[17] = 0;
    nyomva++;
  }
  else if (man4[17] == 1 and lman4[17]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman4[17] = 1;
    nyomva--;
  }
  */
  if (man4[18] == 0 and lman4[18]==1) {
    MidiSend(noteOn2, 51, velocity);
    lman4[18] = 0;
    nyomva++;
  }
  else if (man4[18] == 1 and lman4[18]==0) {
    MidiSend(noteOff2, 51, velocity);
    lman4[18] = 1;
    nyomva--;
  }
  if (man4[19] == 0 and lman4[19]==1) {
    MidiSend(noteOn2, 66, velocity);
    lman4[19] = 0;
    nyomva++;
  }
  else if (man4[19] == 1 and lman4[19]==0) {
    MidiSend(noteOff2, 66, velocity);
    lman4[19] = 1;
    nyomva--;
  }
  if (man4[20] == 0 and lman4[20]==1) {
    MidiSend(noteOn2, 52, velocity);
    lman4[20] = 0;
    nyomva++;
  }
  else if (man4[20] == 1 and lman4[20]==0) {
    MidiSend(noteOff2, 52, velocity);
    lman4[20] = 1;
    nyomva--;
  }
  if (man4[21] == 0 and lman4[21]==1) {
    MidiSend(noteOn2, 65, velocity);
    lman4[21] = 0;
    nyomva++;
  }
  else if (man4[21] == 1 and lman4[21]==0) {
    MidiSend(noteOff2, 65, velocity);
    lman4[21] = 1;
    nyomva--;
  }
  if (man4[22] == 0 and lman4[22]==1) {
    MidiSend(noteOn2, 53, velocity);
    lman4[22] = 0;
    nyomva++;
  }
  else if (man4[22] == 1 and lman4[22]==0) {
    MidiSend(noteOff2, 53, velocity);
    lman4[22] = 1;
    nyomva--;
  }
  if (man4[23] == 0 and lman4[23]==1) {
    MidiSend(noteOn2, 64, velocity);
    lman4[23] = 0;
    nyomva++;
  }
  else if (man4[23] == 1 and lman4[23]==0) {
    MidiSend(noteOff2, 64, velocity);
    lman4[23] = 1;
    nyomva--;
  }
  if (man4[24] == 0 and lman4[24]==1) {
    MidiSend(noteOn2, 54, velocity);
    lman4[24] = 0;
    nyomva++;
  }
  else if (man4[24] == 1 and lman4[24]==0) {
    MidiSend(noteOff2, 54, velocity);
    lman4[24] = 1;
    nyomva--;
  }
  if (man4[25] == 0 and lman4[25]==1) {
    MidiSend(noteOn2, 63, velocity);
    lman4[25] = 0;
    nyomva++;
  }
  else if (man4[25] == 1 and lman4[25]==0) {
    MidiSend(noteOff2, 63, velocity);
    lman4[25] = 1;
    nyomva--;
  }
  if (man4[26] == 0 and lman4[26]==1) {
    MidiSend(noteOn2, 55, velocity);
    lman4[26] = 0;
    nyomva++;
  }
  else if (man4[26] == 1 and lman4[26]==0) {
    MidiSend(noteOff2, 55, velocity);
    lman4[26] = 1;
    nyomva--;
  }
  if (man4[27] == 0 and lman4[27]==1) {
    MidiSend(noteOn2, 62, velocity);
    lman4[27] = 0;
    nyomva++;
  }
  else if (man4[27] == 1 and lman4[27]==0) {
    MidiSend(noteOff2, 62, velocity);
    lman4[27] = 1;
    nyomva--;
  }
  if (man4[28] == 0 and lman4[28]==1) {
    MidiSend(noteOn2, 56, velocity);
    lman4[28] = 0;
    nyomva++;
  }
  else if (man4[28] == 1 and lman4[28]==0) {
    MidiSend(noteOff2, 56, velocity);
    lman4[28] = 1;
    nyomva--;
  }
  if (man4[29] == 0 and lman4[29]==1) {
    MidiSend(noteOn2, 61, velocity);
    lman4[29] = 0;
    nyomva++;
  }
  else if (man4[29] == 1 and lman4[29]==0) {
    MidiSend(noteOff2, 61, velocity);
    lman4[29] = 1;
    nyomva--;
  }
  if (man4[30] == 0 and lman4[30]==1) {
    MidiSend(noteOn2, 57, velocity);
    lman4[30] = 0;
    nyomva++;
  }
  else if (man4[30] == 1 and lman4[30]==0) {
    MidiSend(noteOff2, 57, velocity);
    lman4[30] = 1;
    nyomva--;
  }
  if (man4[31] == 0 and lman4[31]==1) {
    MidiSend(noteOn2, 60, velocity);
    lman4[31] = 0;
    nyomva++;
  }
  else if (man4[31] == 1 and lman4[31]==0) {
    MidiSend(noteOff2, 60, velocity);
    lman4[31] = 1;
    nyomva--;
  }
  if (man4[32] == 0 and lman4[32]==1) {
    MidiSend(noteOn2, 72, velocity);
    lman4[32] = 0;
    nyomva++;
  }
  else if (man4[32] == 1 and lman4[32]==0) {
    MidiSend(noteOff2, 72, velocity);
    lman4[32] = 1;
    nyomva--;
  }
  if (man4[33] == 0 and lman4[33]==1) {
    MidiSend(noteOn2, 71, velocity);
    lman4[33] = 0;
    nyomva++;
  }
  else if (man4[33] == 1 and lman4[33]==0) {
    MidiSend(noteOff2, 71, velocity);
    lman4[33] = 1;
    nyomva--;
  }
  if (man4[34] == 0 and lman4[34]==1) {
    MidiSend(noteOn2, 73, velocity);
    lman4[34] = 0;
    nyomva++;
  }
  else if (man4[34] == 1 and lman4[34]==0) {
    MidiSend(noteOff2, 73, velocity);
    lman4[34] = 1;
    nyomva--;
  }
  if (man4[35] == 0 and lman4[35]==1) {
    MidiSend(noteOn2, 70, velocity);
    lman4[35] = 0;
    nyomva++;
  }
  else if (man4[35] == 1 and lman4[35]==0) {
    MidiSend(noteOff2, 70, velocity);
    lman4[35] = 1;
    nyomva--;
  }
  if (man4[36] == 0 and lman4[36]==1) {
    MidiSend(noteOn2, 74, velocity);
    lman4[36] = 0;
    nyomva++;
  }
  else if (man4[36] == 1 and lman4[36]==0) {
    MidiSend(noteOff2, 74, velocity);
    lman4[36] = 1;
    nyomva--;
  }
  if (man4[37] == 0 and lman4[37]==1) {
    MidiSend(noteOn2, 69, velocity);
    lman4[37] = 0;
    nyomva++;
  }
  else if (man4[37] == 1 and lman4[37]==0) {
    MidiSend(noteOff2, 69, velocity);
    lman4[37] = 1;
    nyomva--;
  }
  if (man4[38] == 0 and lman4[38]==1) {
    MidiSend(noteOn2, 75, velocity);
    lman4[38] = 0;
    nyomva++;
  }
  else if (man4[38] == 1 and lman4[38]==0) {
    MidiSend(noteOff2, 75, velocity);
    lman4[38] = 1;
    nyomva--;
  }
  if (man4[39] == 0 and lman4[39]==1) {
    MidiSend(noteOn2, 68, velocity);
    lman4[39] = 0;
    nyomva++;
  }
  else if (man4[39] == 1 and lman4[39]==0) {
    MidiSend(noteOff2, 68, velocity);
    lman4[39] = 1;
    nyomva--;
  }
  if (man4[40] == 0 and lman4[40]==1) {
    MidiSend(noteOn2, 76, velocity);
    lman4[40] = 0;
    nyomva++;
  }
  else if (man4[40] == 1 and lman4[40]==0) {
    MidiSend(noteOff2, 76, velocity);
    lman4[40] = 1;
    nyomva--;
  }
  if (man4[41] == 0 and lman4[41]==1) {
    MidiSend(noteOn2, 67, velocity);
    lman4[41] = 0;
    nyomva++;
  }
  else if (man4[41] == 1 and lman4[41]==0) {
    MidiSend(noteOff2, 67, velocity);
    lman4[41] = 1;
    nyomva--;
  }
  if (man4[42] == 0 and lman4[42]==1) {
    MidiSend(noteOn2, 77, velocity);
    lman4[42] = 0;
    nyomva++;
  }
  else if (man4[42] == 1 and lman4[42]==0) {
    MidiSend(noteOff2, 77, velocity);
    lman4[42] = 1;
    nyomva--;
  }
  /*NC
  if (man4[43] == 0 and lman4[43]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman4[43] = 0;
    nyomva++;
  }
  else if (man4[43] == 1 and lman4[43]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman4[43] = 1;
    nyomva--;
  }
  */
  if (man4[44] == 0 and lman4[44]==1) {
    MidiSend(noteOn2, 78, velocity);
    lman4[44] = 0;
    nyomva++;
  }
  else if (man4[44] == 1 and lman4[44]==0) {
    MidiSend(noteOff2, 78, velocity);
    lman4[44] = 1;
    nyomva--;
  }
  if (man4[45] == 0 and lman4[45]==1) {
    MidiSend(noteOn2, 89, velocity);
    lman4[45] = 0;
    nyomva++;
  }
  else if (man4[45] == 1 and lman4[45]==0) {
    MidiSend(noteOff2, 89, velocity);
    lman4[45] = 1;
    nyomva--;
  }
  if (man4[46] == 0 and lman4[46]==1) {
    MidiSend(noteOn2, 79, velocity);
    lman4[46] = 0;
    nyomva++;
  }
  else if (man4[46] == 1 and lman4[46]==0) {
    MidiSend(noteOff2, 79, velocity);
    lman4[46] = 1;
    nyomva--;
  }
  if (man4[47] == 0 and lman4[47]==1) {
    MidiSend(noteOn2, 88, velocity);
    lman4[47] = 0;
    nyomva++;
  }
  else if (man4[47] == 1 and lman4[47]==0) {
    MidiSend(noteOff2, 88, velocity);
    lman4[47] = 1;
    nyomva--;
  }
  if (man4[48] == 0 and lman4[48]==1) {
    MidiSend(noteOn2, 80, velocity);
    lman4[48] = 0;
    nyomva++;
  }
  else if (man4[48] == 1 and lman4[48]==0) {
    MidiSend(noteOff2, 80, velocity);
    lman4[48] = 1;
    nyomva--;
  }
  /*ez az ami nincs használva (39es pin)
  if (man4[49] == 0 and lman4[49]==1) {
    MidiSend(noteOn2, ??, velocity);
    lman4[49] = 0;
    nyomva++;
  }
  else if (man4[49] == 1 and lman4[49]==0) {
    MidiSend(noteOff2, ??, velocity);
    lman4[49] = 1;
    nyomva--;
  }
  */
  if (man4[50] == 0 and lman4[50]==1) {
    MidiSend(noteOn2, 81, velocity);
    lman4[50] = 0;
    nyomva++;
  }
  else if (man4[50] == 1 and lman4[50]==0) {
    MidiSend(noteOff2, 81, velocity);
    lman4[50] = 1;
    nyomva--;
  }
  if (man4[51] == 0 and lman4[51]==1) {
    MidiSend(noteOn2, 96, velocity);
    lman4[51] = 0;
    nyomva++;
  }
  else if (man4[51] == 1 and lman4[51]==0) {
    MidiSend(noteOff2, 96, velocity);
    lman4[51] = 1;
    nyomva--;
  }
  if (man4[52] == 0 and lman4[52]==1) {
    MidiSend(noteOn2, 82, velocity);
    lman4[52] = 0;
    nyomva++;
  }
  else if (man4[52] == 1 and lman4[52]==0) {
    MidiSend(noteOff2, 82, velocity);
    lman4[52] = 1;
    nyomva--;
  }
  if (man4[53] == 0 and lman4[53]==1) {
    MidiSend(noteOn2, 95, velocity);
    lman4[53] = 0;
    nyomva++;
  }
  else if (man4[53] == 1 and lman4[53]==0) {
    MidiSend(noteOff2, 95, velocity);
    lman4[53] = 1;
    nyomva--;
  }
  if (man4[54] == 0 and lman4[54]==1) {
    MidiSend(noteOn2, 83, velocity);
    lman4[54] = 0;
    nyomva++;
  }
  else if (man4[54] == 1 and lman4[54]==0) {
    MidiSend(noteOff2, 83, velocity);
    lman4[54] = 1;
    nyomva--;
  }
  if (man4[55] == 0 and lman4[55]==1) {
    MidiSend(noteOn2, 94, velocity);
    lman4[55] = 0;
    nyomva++;
  }
  else if (man4[55] == 1 and lman4[55]==0) {
    MidiSend(noteOff2, 94, velocity);
    lman4[55] = 1;
    nyomva--;
  }
  if (man4[56] == 0 and lman4[56]==1) {
    MidiSend(noteOn2, 84, velocity);
    lman4[56] = 0;
    nyomva++;
  }
  else if (man4[56] == 1 and lman4[56]==0) {
    MidiSend(noteOff2, 84, velocity);
    lman4[56] = 1;
    nyomva--;
  }
  if (man4[57] == 0 and lman4[57]==1) {
    MidiSend(noteOn2, 93, velocity);
    lman4[57] = 0;
    nyomva++;
  }
  else if (man4[57] == 1 and lman4[57]==0) {
    MidiSend(noteOff2, 93, velocity);
    lman4[57] = 1;
    nyomva--;
  }
  if (man4[58] == 0 and lman4[58]==1) {
    MidiSend(noteOn2, 85, velocity);
    lman4[58] = 0;
    nyomva++;
  }
  else if (man4[58] == 1 and lman4[58]==0) {
    MidiSend(noteOff2, 85, velocity);
    lman4[58] = 1;
    nyomva--;
  }
  if (man4[59] == 0 and lman4[59]==1) {
    MidiSend(noteOn2, 92, velocity);
    lman4[59] = 0;
    nyomva++;
  }
  else if (man4[59] == 1 and lman4[59]==0) {
    MidiSend(noteOff2, 92, velocity);
    lman4[59] = 1;
    nyomva--;
  }
  if (man4[60] == 0 and lman4[60]==1) {
    MidiSend(noteOn2, 86, velocity);
    lman4[60] = 0;
    nyomva++;
  }
  else if (man4[60] == 1 and lman4[60]==0) {
    MidiSend(noteOff2, 86, velocity);
    lman4[60] = 1;
    nyomva--;
  }
  if (man4[61] == 0 and lman4[61]==1) {
    MidiSend(noteOn2, 91, velocity);
    lman4[61] = 0;
    nyomva++;
  }
  else if (man4[61] == 1 and lman4[61]==0) {
    MidiSend(noteOff2, 91, velocity);
    lman4[61] = 1;
    nyomva--;
  }
  if (man4[62] == 0 and lman4[62]==1) {
    MidiSend(noteOn2, 87, velocity);
    lman4[62] = 0;
    nyomva++;
  }
  else if (man4[62] == 1 and lman4[62]==0) {
    MidiSend(noteOff2, 87, velocity);
    lman4[62] = 1;
    nyomva--;
  }
  if (man4[63] == 0 and lman4[63]==1) {
    MidiSend(noteOn2, 90, velocity);
    lman4[63] = 0;
    nyomva++;
  }
  else if (man4[63] == 1 and lman4[63]==0) {
    MidiSend(noteOff2, 90, velocity);
    lman4[63] = 1;
    nyomva--;
  }
}

void MidiSend(int one, int two, int three) {
  Serial.write(one);
  Serial.write(two);
  Serial.write(three);
}
