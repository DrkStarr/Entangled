
! ---------------------------------------------------------------------------- !
!       MAIN STREET. 08/10/16
!
  Room    gravelRoad "Main Street"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              SelfPlayer.sawJerryLeave = false;
              if (currentTime()) {
                  print "On the north side of the street sits a sign telling people they're entering Sunnybrook. To the south, a path leads to the gas station. ";
                  if (self.attendantQuestioned) print "Cops question the attendant over at the shop. ";
                  print "To the west down Main Street, the road will take you to the bowling alley";
                  if (gasStation.playerEntangled == false) {
                      gasStation.playerEntangled = true;
                      self.sorryScientist = true;
                      StartDaemon(gravelRoadObj);
                      move gasStationScientist to self;
                      move notes to self;
                      print ".^^From behind a deranged-looking scientist bumps into you.
                      ^^~Oh sorry,~ he exclaims, dropping his notes by accident. Turning,
                      he walks west down the street and out of sight";
                  } else {
                      if (iScientist == 3) {
                          print ".^^The scientist is out of sight, taking off down the street to the west";
                      }
                      if (self.triedToFollowScientistLate) {
                          self.triedToFollowScientistLate = false;
                          print ".^^The scientist is nowhere to be seen";
                      }
                  }
                  if (iAttendantCall >= 24 && self.examineStation) {
                      self.examineStation = false;
                      self.attendantQuestioned = true;
                      gravelRoadGasStation.&name-->3 = 'officer';
                      gravelRoadGasStation.&name-->4 = 'officers';
                      gravelRoadGasStation.&name-->5 = 'cop';
                      gravelRoadGasStation.&name-->6 = 'cops';
                      gravelRoadGasStation.&name-->8 = 'police';
                      move gravelRoadCruiser to self;
                      print ".^^A black and white pulls up in the gas station behind you";
                      if (self.copsPrintExtra) print ". The lights are flashing with the sirens off";
                      print ". Once parked, the officers get out and question the attendant";
                  } else {
                      if (iAttendantCall > 0) StartDaemon (self);
                  }
                  iScientist = 0;
                  iCharacterTalkDelay = 0;
                  StopDaemon (gasStation);
                  StopDaemon (gasStationMark);
                  StopDaemon (gasStationBooth);
                  if (gasStationBooth.attendantCall) {
                      gasStationBooth.attendantCall = false;
                      gasStationMark.angryAttendant = true;
                  }
                  ".";
              }
              "On the north side of the street, a sign tells people they're entering Sunnybrook.
              To the south, a path leads to the gas station. The road out of town continues east, meeting up with the highway.
              It also runs west back into the city.";
          ],
          e_to [;
              if (basement.firstTime) "You're not going to walk out of town. Springfield is over 30 miles away. You can go south or west.";
              "You're not going to walk out of town. Melville is over 20 miles away. You can go south or west.";
          ],
          w_to [;
              <<Enter gravelRoadBusStop>>;
          ],
          s_to [;
              <<Enter gravelRoadGasStation>>;
          ],
          cant_go [;
              "You can go south to the gas station or west to the bus stop.";
          ],
          before [;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sorry:
                  if (self.sorryScientist) "The scientist walked down the street to the west.";
              Wave:

              Sleep:
                  return roomSleep();
          ],
          daemon [;
              iAttendantCall++;
              switch (iAttendantCall) {
                  26: if (player in gravelRoad) {
                          self.examineStation = false;
                          self.attendantQuestioned = true;
                          gravelRoadPhone.copsCame = true;
                          gravelRoadGasStation.&name-->3 = 'officer';
                          gravelRoadGasStation.&name-->4 = 'officers';
                          gravelRoadGasStation.&name-->5 = 'cop';
                          gravelRoadGasStation.&name-->6 = 'cops';
                          gravelRoadGasStation.&name-->8 = 'police';
                          move gravelRoadCruiser to self;
                          "^A black and white pulls up in the gas station behind you. The lights are flashing
                          with the sirens off. Once parked, the officers get out and question the attendant.";
                      }
                      if (player in gasStation) {
                          print "^A black and white comes down the street, lights flashing with the sirens off.
                          You head north before anybody notices.^";
                          gravelRoadPhone.copsCame = true;
                          gravelRoad.copsPrintExtra = false;
                          PlayerTo(gravelRoad);
                          rtrue;
                      }
                      self.examineStation = false;
                      self.attendantQuestioned = true;
                      gravelRoadPhone.copsCame = true;
                      gravelRoadGasStation.&name-->3 = 'officer';
                      gravelRoadGasStation.&name-->4 = 'officers';
                      gravelRoadGasStation.&name-->5 = 'cop';
                      gravelRoadGasStation.&name-->6 = 'cops';
                      gravelRoadGasStation.&name-->8 = 'police';
                      move gravelRoadCruiser to self;
                  }
          ],
          firstTime true,
          copsPrintExtra true,
          examineStation true,
          attendantQuestioned false,
          sorryScientist false,
          triedToFollowScientistLate false;

! 08/10/16

  RoomObj -> gravelRoadObj "Main Street"
    with  name 'main' 'road' 'area' 'street',
          description [;
              <<Look gravelRoad>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          daemon [;
              if (self.iDaemonWait) {
                  self.iDaemonWait = false;
              } else {
                  if (gravelRoad.sorryScientist) {
                      gravelRoad.sorryScientist = false;
                      StopDaemon(self);
                  }
              }
          ],
          iDaemonWait true,
     has  proper;

! 08/10/16

  OutRch  -> gravelRoadGasStation "gas station"
    with  name 'gas' 'station' 'building' 'ph000101' 'ph000102' 'ph000103' 'ph000104' 'shop' 'ph000105',
          before [;
              Enter, Go:
                  if (currentTime()) {
                      if (gravelRoad.examineStation == false) "Not unless you want to get arrested.";
                  }
                  PlayerTo(gasStation);
                  rtrue;
              Examine:
                  if (currentTime()) {
                      if (gravelRoad.examineStation == false)
                          "Two officers stand outside their cruiser, questioning the attendant.";
                      "The only life over at the gas station is the attendant who's glued to his phone.";
                  }
                  if (conanComic.giveToJerry) "The only life over at the gas station is the attendant who's glued to a comic book.";
                  "The only life over at the gas station is the attendant who's glued to the television.";
              WaveObject:
                  if (gravelRoad.examineStation == false) "Not unless you want to get arrested.";
          ],
          examineStation false;

! 08/10/16

  OutRch  -> gravelRoadAttendant "attendant"
    with  name 'ph000801' 'mark' 'attendant' 'teen' 'man' 'guy' 'dude',
          before [;
              Enter, Go:
                  <<Enter gravelRoadGasStation>>;
              Examine, WaveObject:
                  if (currentTime()) {
                      if (gravelRoad.examineStation == false)
                          "The attendant is talking to the officers. He shifts around looking, uncomfortable.";
                      if (iAttendantCall >= 1 && iAttendantCall <= 6) "The attendant is on the phone, still talking to the cops.";
                      "He doesn't notice you. He's playing with his phone.";
                  }
                  if (gasStationJerry in gasStation) {
                      if (gasStationComic in gasStation) "The overweight teen pays you no mind reading the comic you gave him.";
                      "An overweight teen pays you no mind as he watches a small portable television.";
                  }
                  "There's no attendant over at the garage right now.";
              default:
                  "You can't do that from here.";
          ],
          life [;
              "You can't do that from here.";
          ],
          order [;
              "You can't do that from here.";
          ],
     has  animate male;

! 11/29/17

  OutRch  -> gravelRoadPhone "phone"
    with  name 'phone' 'iphone',
          before [;
              Enter, Go:
                  <<Enter gravelRoadGasStation>>;
              Examine:
                  if (self.copsCame) "The attendant holds on to the phone, talking to the cops.";
                  if (iAttendantCall >= 1 && iAttendantCall <= 6) "The attendant is on the phone, still talking to the cops.";
                  "The attendant taps away at the phone, sending texts or playing games.";
          ],
          copsCame false;

! 08/25/20

  OutRch  -> gravelRoadPath "path"
    with  name 'path' 'trail',
          before [;
              Examine:
                  "The path runs south towards the gas station.";
              Follow:
                  <<Enter gravelRoadGasStation>>;
          ];

! 08/10/16

  OutRch  -> gravelRoadBusStop "bus stop"
    with  name 'bus' 'stop',
          before [;
              Enter, Go:
                  PlayerTo(busStop);
                  rtrue;
              Examine:
                  "There's a bus stop west. It's barely lit with an awning to protect passengers.";
          ];

! 1/18/17

  Object  -> busStopSign "sign"
    with  name 'sign' 'sunny' 'brook' 'sunnybrook',
          before [;
              Examine, Search:
                  if (currentTime())
                      "The name of the city is in big white letters on a green background. Underneath it says: Population 342";
                  print "The name of the city is in big white letters on a green background. Underneath it says: Population 508";
                  if (self.firstLook) {
                      self.firstLook = false;
                      ". Last time you checked, the population was less than 350.";
                  }
                  ".";
              Climb:
                  "It's not that tall - about ten feet. But you're not going to get anywhere climbing it.";
              LookUnder:
                  "The sign is made from a thin piece of metal. There's nothing attached to it.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The sign doesn't need to go anywhere.";
          ],
          firstLook true,
     has  concealed static;

! 12/15/16

  OutRch  gravelRoadCruiser "cruiser"
    with  name 'car' 'cruiser' 'black' 'white' 'county',
          before [;
              Examine:
                  "The cruiser's parked. Lights still flashing.";
          ];


! 11/29/17

  OutRch  gravelRoadTV "television"
    with  name 'tv' 'television' 'telly' 'small' 'portable',
          before [;
              Examine:
                  if (gasStationJerry in gasStation) {
                      if (conanComic.giveToJerry) "The television is turned off with the attendant reading a comic.";
                      "The attendant is glued to the small portable television.";
                  }
                  if (conanComic.giveToJerry) "No one is in the booth. The television is turned off.";
                  "The television sits in the booth. No one is watching it.";
          ],
     has  concealed static;


! 11/29/17

  TooFar  gravelRoadComic "comic"
    with  name 'conan' 'comic' '115',
          before [;
              Examine, Search:
                  "It's too far to see from here.";
              Enter, Go:
                  <<Enter gravelRoadGasStation>>;
          ];


! 10/03/19

  ORchSc  gravelRoadScientist "scientist"
    with  name 'scientist',
          before [;
              Examine:
                  "You can't see him anymore.";
              Follow:
                  "He's gone.";
              default:
                  "You can't see him anymore.";
          ],
          life [;
              "You can't see him anymore.";
          ],
     has  animate male scenery;
