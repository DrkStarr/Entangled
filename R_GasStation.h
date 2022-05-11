!
!
! ---------------------------------------------------------------------------- !
!       GAS STATION. 08/05/16
!
  Room    gasStation "Gas Station"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  StartDaemon(self);
                  StartDaemon(gasStationMark);
              }
              SelfPlayer.outside = true;
              if (currentTime()) {
                  if (self.currentFirstTime) {
                      print "This gas station is where everybody from the trailer park gets their cigarettes. It";
                  } else {
                      print "The station";
                  }
                  print " sits on the south side of Main Street. The open lot has
                  a couple of pumps surrounding a booth in the middle.
                  A garage sits off to the side under a digital sign. The path continues north to Main Street.
                  South you can follow it back up the cliff.^";
                  if (self.currentFirstTime) {
                      self.currentFirstTime = false;
                      "^Mark's working the booth today. Jerry must have taken the night off.
                      You wave at him, but he's ignoring you while playing with his phone.";
                  } else {
                      if (gasStationBooth.attendantCall) "^The attendant that works the booth is talking on the phone.";
                      else {
                          if (gasStationMark.eyesOpen) {
                              gasStationMark.eyesOpen = false;
                              "^An attendant works the booth turning back to his phone.";
                          }
                          "^An attendant works the booth messing with his phone.";
                      }
                  }
              }
              SelfPlayer.startMoveJerry = true;
              print "The station sits on the south side of Main Street. It's an open lot that has
              a car parked in front of the garage. In the center of the station is a booth. ";
              if (gasStationJerry in self) {
                  if (conanComic.giveToJerry) print "An attendant reads a comic inside";
                  else print "An attendant watches television inside";
              } else print "Currently empty";
              print ". A backlit sign towers above it all. There's a path heading north to Main Street. South it goes up the cliff";
              if (gasStationJerry in self) {
                  if (self.pastFirstTime) {
                      StartDaemon(gasStationJerry);
                  }
                  if (iMinute == 10) ".";
                  if (iMinute == 20) ".";
                  if (iMinute == 30) ".";
                  if (iMinute == 40) ".";
                  if (conanComic.giveToJerry) {
                      print ".^^The attendant relaxes, reading a comic while working the booth";
                  } else {
                      print ".^^The attendant relaxes, watching a small television while working the booth";
                  }
                  if (self.pastFirstTime) {
                      self.pastFirstTime = false;
                      ". But it's not Mark.";
                  }
              } else {
                  print ".^^The booth in the center of the station is empty. The attendant missing";
              }
              ".";
          ],
          daemon [;
              iScientist++;
              if (iScientist == 3) {
                  self.playerEntangled = true;
                  gasStationMark.seenScientist = true;
                  move gasStationScientist to self;
                  move gravelRoadScientist to gravelRoad;
                  move notes to self;
                  "^From behind a deranged-looking scientist bumps into you.
                  ^^~Oh sorry,~ he exclaims, dropping his notes by accident. Turning, he walks north to the road.";
              }
              if (iScientist == 4) {
                  "^The scientist walks down the street, out of sight.";
              }
          ],
          n_to [;
              <<Enter gasStationRoad>>;
          ],
          s_to [;
              <<Enter gasStationCliff>>;
          ],
          u_to [;
              <<Enter gasStationCliff>>;
          ],
          cant_go [;
              "You can go north to the street or south back up the cliff.";
          ],
          before [;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (gasStationBooth.attendantCall) "You listen to the attendant, complain to the cops.";
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sorry:
                  if (iScientist == 3) {
                      StopDaemon(self);
                      iScientist = 0;
                      "Turning back, the scientist gives a short grunt. Then he walks down the street, out of sight.";
                  }
                  if (currentTime()) <<Answer t_sorry gasStationMark>>;
                  if (gasStationJerry in gasStation) <<Answer t_sorry gasStationJerry>>;
              Wave:

              Yes:
                  if (currentTime()) <<Answer t_yes gasStationMark>>;
                  if (gasStationJerry in gasStation) <<Answer t_yes gasStationJerry>>;
              No:
                  if (currentTime()) <<Answer t_no gasStationMark>>;
                  if (gasStationJerry in gasStation) <<Answer t_no gasStationJerry>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          pastFirstTime true,
          currentFirstTime true,
          playerEntangled false;

! 08/05/16

  RoomObj -> gasStationObj "station"
    with  name 'gas' 'station' 'area' 'place' 'lot',
          description [;
              <<Look gasStation>>;
          ],
          before [;
              Search:
                  "You look around the station finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/05/16

  Object  -> gasStationBooth "booth"
    with  name 'booth' 'door' 'glass' 'plexiglas' 'plexiglass',
          before [;
              Attack, Kick:
                  if (basement.firstTime) {
                      if (gasStationMark.angryAttendant)
                          "~If I were you, I'd get out of here. County is going to be pissed when they show up.~";
                      if (self.attendantCall)
                          "The attendant is on the phone calling the cops. You should get out of here.";
                      if (self.boothAttacked) {
                          self.attendantCall = true;
                          StartDaemon(self);
                          "~That's it. I'm not putting up with you,~ Mark says, looking down at his phone calling 911.";
                      }
                      self.boothAttacked = true;
                      "~You better move along,~ the attendant says from inside the booth, ~or I'm going to call the cops.
                      County might take a while to get out here, but they'll be doubly pissed at you.~";
                  }
                  if (gasStationJerry in gasStation) {
                      if (self.boothAttacked) "~Go for a walk and cool off.~";
                      self.boothAttacked = true;
                      "~Hey, why so uptight? Go for a walk and cool off. It might help.~";
                  }
              Unlock:
                  if (currentTime()) {
                      <<Attack self>>;
                  }
                  if (gasStationJerry in gasStation) "~You're just wasting your time. Why don't you find something else to do?~";
                  if (second == shedKey) "You try the key, but it doesn't fit the lock.";
                  "You can't unlock the booth with that.";
              Examine:
                  if (basement.firstTime)
                      "The booth is dark. Inside the lights blown out, but the attendant doesn't mind playing with his phone. Gas pumps lie on either side.";
                  if (gasStationJerry in gasStation) {
                      if (conanComic.giveToJerry) {
                          "The booth is lit, with the attendant turning on the light to read the comic. He sits inside, flipping through the pages.";
                      } else {
                          "The booth is dark, and the attendant sits there watching a fight on T.V.";
                      }
                  }
                  if (conanComic.giveToJerry) {
                      "The booth is lit. The attendant needed to turn on the light to read the comic. But it's empty inside.";
                  }
                  "The booth is dark, and no one is inside. A T.V. displays a fight on the screen.";
              Search:
                  "You can't, the booth's locked.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gas station.";
              Knock:
                  if (basement.firstTime) {
                      if (testAngryAttendant()) rtrue;
                      if (gasStationMark.eyesOpen) {
                          gasStationMark.eyesOpen = false;
                          "~I hear you. I hear you. What do you want?~ he asks, looking back down at his phone.";
                      }
                      "~I hear you. I hear you. What do you want?~ he asks, not looking up.";
                  }
                  if (gasStationJerry in gasStation) {
                      print "~I am right here,~ the attendant says";
                      if (gasStationJerry.eyesOpen == false) {
                          gasStationJerry.eyesOpen = true;
                          print " looking up";
                      }
                      ", ~What do you want?~";
                  }
                  "The booth is empty. No one's inside.";
              Enter, Open, Push:
                  if (basement.firstTime) {
                      if (gasStationMark.angryAttendant)
                          "The door's locked.  ~If I were you, I'd get out of here,~ says the attendant.";
                      if (gasStationBooth.attendantCall)
                          "The attendant is on the phone and not paying attention, but the door's locked.";
                      if (self.openWithAngryAttendant) {
                          self.attendantCall = true;
                          StartDaemon(self);
                          "~That's it. I'm not putting up with you,~ Mark says, looking down at his phone calling 911.";
                      }
                      if (self.triedToOpen) {
                          self.openWithAngryAttendant = true;
                          "~Stop screwing around, or I'm going to call the cops.~";
                      }
                      self.triedToOpen = true;
                      gasStationMark.eyesOpen = true;
                      "~What do you think you're doing,~ he yells, checking that the door is locked.";
                  }
                  if (gasStationJerry in gasStation) {
                      print "~The door's locked,~ the attendant says, ";
                      if (gasStationJerry.eyesOpen) {
                          gasStationJerry.eyesOpen = false;
                          print "looking back at";
                      } else {
                          print "not looking up from";
                      }
                      if (conanComic.giveToJerry) {
                          " the comic. ~You're just wasting your time.~";
                      } else {
                          " the T.V. ~You're just wasting your time.~";
                      }
                  }
                  "The door was locked when the attendant went to the bathroom.";
          ],
          daemon [;
              iAttendantCall++;
              switch (iAttendantCall) {
                  2: "^Mark puts the phone to his ear, ~Yeah, I'd like to report a robbery at 260 Main Street.~";
                  3: "^~Yeah. A robbery. I got someone trying to break into the place.~";
                  5: "^~Well get them out here as fast as can.~";
                  6: self.attendantCall = false;
                     gasStationMark.eyesOpen = true;
                     gasStationMark.angryAttendant = true;
                     "^~You're in it deep,~ he says, hanging up the phone.";
                  24: "^~I'm sure County is going to be here soon. I'm surprised you're even here.~";
                  26: print "^A black and white comes down the street, lights flashing with the sirens off.
                      You head north before anybody notices.^";
                      gravelRoadPhone.copsCame = true;
                      gravelRoad.copsPrintExtra = false;
                      PlayerTo(gravelRoad);
                      rtrue;
              }
          ],
          triedToOpen false,
          boothAttacked false,
          attendantCall false,
          openWithAngryAttendant false,
     has  concealed static openable ~open;

! 08/10/16

  OutRch  -> gasStationRoad "Main Street"
    with  name 'gravel' 'main' 'road' 'street',
          before [;
              Enter, Go:
                  PlayerTo(gravelRoad);
                  rtrue;
              Examine:
                  print "Main Street runs east to west in front of the gas station";
                  if (gasStation.playerEntangled && iScientist == 3) ". The scientist turns walking down the road.";
                  print " and is empty";
                  if (livingRoomWindow.settingSun || SelfPlayer.eveningTime || SelfPlayer.nightTime) " tonight.";
                  ".";
          ],
          daemon [;
              if (player in gasStation) {
                  if (iMinute == 10) "^The attendant takes a sip from the soda he's drinking.";
                  if (iMinute == 20) "^The attendant raises the soda to his lips, sipping on it a few times.";
                  if (iMinute == 30) "^The attendant swishes the soda around before taking a sip.";
                  if (iMinute == 40) "^The attendant looks down the neck of the bottle before taking a final swig.";
                  }
          ],
     has  proper;

! 08/16/16

  OutRch  -> gasStationCliff "cliff"
    with  name 'cliff' 'trailer' 'park',
          before [;
              Climb:
                  "That's a bit extreme. Why don't you try the path?";
              Enter, Go:
                  if (currentTime()) {
                      "Not without Sam.";
                  }
                  PlayerTo(cliff);
                  rtrue;
              Examine:
                  "Up at the top of the cliff is the trailer park. A path comes down from there continuing north.";
          ];

! 08/16/16

  OutRch  -> gasStationPath "path"
    with  name 'path' 'trail',
          before [;
              Climb, Enter, Go:
                  "It goes in two directions. North or south.";
              Examine:
                  "The path runs north to Main Street or south to the trailer park.";
              Follow:
                  if (currentTime()) <<Enter gasStationRoad>>;
                  <<Enter gasStationCliff>>;
          ];

! 05/24/17

  OutRch  -> gasStationField "field"
    with  name 'field',
          before [;
              Examine:
                  "The field is on the other side of the street and pretty far away. It's hard to see.";
          ];

! 01/30/18

  Object  -> gasStationGarage "garage"
    with  name 'garage' 'building' 'place' 'doors',
          before [;
              Enter, Go:
                  "The doors are closed. Lights are off. And you don't belong in there.";
              Close:
                  "You don't need to do that.";
              Open:
                  if (basement.firstTime) "The attendant would see you. That's not a good idea.";
                  if (gasStationJerry in gasStation) "The attendant would see you. That's not a good idea.";
                  "You don't need to do that.";
              Examine, Search:
                  if (basement.firstTime)
                      "The garage sits under a neon sign. Its doors closed and lights
                      turned off. There's a bathroom next to it that's poorly constructed.
                      A shoddy design that barely passes code.";
                  "The garage is as big as you remember it, but it has a fresh coat of green paint. The bathroom next to it still looks beat and would barely pass code.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gas station.";
          ],
    has   concealed static;

! 01/30/18

  Object  -> gasStationBathroom "bathroom"
    with  name 'bathroom' 'lavatory' 'washroom' 'head' 'door',
          before [;
              Enter, Go, Open:
                  if (basement.firstTime) "The door's locked, you need a key to get in there.";
                  if (gasStationJerry in gasStation) "The door's locked, you need a key to get in there.";
                  "The attendant's in there. You need to wait until he gets out.";
              Close:
                  "You don't need to do that.";
              Examine, Search:
                  print "It's a small attachment tacked on to the side of the garage, but it's a poor design that's hardly standing";
                  if (basement.firstTime) ". None of the attendants have ever let you use it.";
                  ".";
              Knock:
                  if (basement.firstTime) "You knock on the door, but no one's in there.";
                  if (gasStationJerry in gasStation) "You knock on the door, but no one's in there.";
                  if (self.knockBathroom) "~God, I said, give me a minute.~";
                  self.knockBathroom = true;
                  "~Give me a minute, would you.~";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gas station.";
              Unlock:
                  if (second == shedKey)"You need a key from the attendant. Not that thing.";
                  "You need a key from the attendant.";
          ],
          knockBathroom false,
    has   concealed static;

! 05/12/18

  OutRch  -> gasStationSign "sign"
    with  name 'digital' 'sign' 'price' 'plastic' 'inserts' 'neon',
          before [;
              Climb:
                  "If you're looking for a better view of the city, you should probably go back up the cliff.";
              Examine, Read:
                  if (basement.firstTime) {
                      print "They took down the old backlit sign a few years ago, replacing it with this digital thing.
                      It displays the price of gasoline at $2.29 a gallon";
                      if (self.signSeen) print ". Ever since the price war on crude ended, the cost has gone up";
                      self.signSeen = false;
                      ".";
                  }
                  "The sign is backlit, but not the price. It's made from plastic inserts that show it at $1.27 a gallon.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gas station.";
          ],
          signSeen true;

! 05/20/18

  Object  -> gasStationPumps "pumps"
    with  name 'pump' 'pumps' 'unleaded' 'ph00520',
          before [;
              Buy:
                  "You don't have a car. There's no tank to fill.";
              Burn:
                  "If you could get it going, the resulting explosion would kill you.";
              Examine, Search:
                  if (basement.firstTime) "Two pumps line the booth, both unleaded.";
                  "Two pumps line the booth. One leaded the other unleaded.";
              SwitchOn:
                  "You could turn on one of the pumps, and gas would go everywhere.
                  But the mess would cause more trouble than it's worth.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The pumps don't need to go anywhere.";
          ],
    has   concealed static pluralname;

! 08/12/16

  ORchCig -> gasStationCigarettes "cigarettes"
    with  name 'cigarettes' 'cigarette' 'cig' 'cigs' 'fag' 'fags' 'smokes',
          before [;
              Buy:
                  if (basement.firstTime) return AskMarkCig();
                  if (gasStationJerry in gasStation) "~I'd gladly sell you a pack but where's your cash.~";
                  "There's no one to buy it from.";
              Examine:
                  if (basement.firstTime) "You can't see them, but you know he's got them inside the booth.";
                  if (gasStationJerry in gasStation) "You can't see them, but you know he's got them inside the booth.";
                  "You can't see them, but you know they're inside the booth.";
          ],
     has  concealed static;

! 08/10/16

  ORchTV  -> gasStationPhone "phone"
    with  name 'phone' 'iphone',
          before [;
              Examine:
                  "It's hard to tell, but it's probably a jailbroken version of the iPhone knowing Mark.";
          ],
      has concealed static;


  Include "NPC_Mark";

! 12/13/16

  ORchSc  gasStationScientist "scientist"
    with  name 'scientist',
          before [;
              Examine:
                  if (iScientist == 3) "The scientist is heading down the street to the west. At least you think he's one, wearing a lab coat with his hair pulled out to the ends.";
                  "You can't see him anymore.";
              Follow, Enter, Go:
                  if (self in gravelRoad || self.followedScientist) "He's gone.";
                  if (iScientist == 3) print "You follow after the scientist, trying to catch up to him.^";
                  else print "You follow after the scientist.^";
                  self.followedScientist = true;
                  if (iScientist == 3) {
                      PlayerTo(gravelRoad);
                      rtrue;
                  }
                  gravelRoad.triedToFollowScientistLate = true;
                  PlayerTo(gravelRoad);
                  rtrue;
          ],
          life [;
              default:
                  if (iScientist == 3) "The scientist crosses the street paying no attention to you as he heads north. At least you think he's one, wearing a lab coat with his hair pulled out to the ends.";
                  "You can't see him anymore.";

          ],
          followedScientist false,
     has  animate male scenery;

! 05/30/17

  ORchTV  gasStationTV "television"
    with  name 'tv' 'television' 'telle' 'tele' 'small' 'portable' 'fight' 'display' 'screen',
          before [;
              Examine:
                  print "The television is a small portable model. ";
                  if (conanComic.giveToJerry) "It's turned off.";
                  if (gasStationJerry in gasStation) "A black and white that keeps the attendant occupied watching two boxers fight it out.";
                  "A black and white that's been left on when the attendant went to the bathroom.
                  Looking at it closer, you see two boxers fighting it out.";
          ],
      has concealed static;

! 06/7/17

  Object  gasStationCar "car"
    with  name 'car' 'vehicle' 'engine' 'hood' 'radiator' 'heart' 'mercury',
          before [;
              Close:
                  if (gasStationJerry in gasStation) "That would only get the attendant's attention.";
                  "You shouldn't do that. It would only advertise you were here.";
              Open:
                  "The hood is open. The car already exposed.";
              Enter, Go:
                  if (gasStationJerry in gasStation) {
                      gasStationJerry.eyesOpen = true;
                      if (gasStationComic in gasStation)
                          "The attendant looks up from the comic, seeing you step over to the car.
                          ~What do you think you're doing?~^^Thinking it over, you step back.";
                      "Stepping up to the car, the attendant scolds you, ~what do you think you're doing?~^
                      ^Thinking it over, you step back.";
                  }
                  "You don't need to do that.";
              Examine:
                  if (self.firstTimeLook) {
                      self.firstTimeLook = false;
                      print "Looking over at the car you see it's";
                  } else {
                      print "The car's";
                  }
                  print " an old Mercury. The hood is up";
                  if (gasStationJerry in gasStation) {
                      if (sparkPlugCar in self) {
                          if (gasStationJerry.askForCar) gasStationJerry.dontKillAskForCar = true;
                          gasStationJerry.askForCar = true;
                          gasStationJerry.eyesOpen = true;
                          " with a spark plug lying on the radiator.^
                          ^~Like it?~ the attendant asks, ~I've put a lot of work into her.~";
                      }
                  }
                  if (sparkPlugCar in self) " with a spark plug lying on the radiator.";
                  print ", its heart exposed to the elements";
                  if (gasStationJerry in gasStation) {
                      if (gasStationJerry.askForCar) gasStationJerry.dontKillAskForCar = true;
                      gasStationJerry.askForCar = true;
                      gasStationJerry.eyesOpen = true;
                      ".^
                      ^~Like it?~ the attendant asks, ~I've put a lot of work into her.~";
                  }
                  ".";
              Fix:
                  if (gasStationJerry in gasStation) "You don't need to get the attendant's attention.";
                  "You don't need to do that.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The car doesn't need to go anywhere.";
              Search:
                  if (gasStationJerry in gasStation) {
                      gasStationJerry.eyesOpen = true;
                      if (gasStationComic in gasStation)
                          "The attendant looks up from the comic, seeing you step over to the car.
                          ~What do you think you're doing?~^^Thinking it over, you step back.";
                      "Stepping up to the car, the attendant scolds you, ~what do you think you're doing?~^
                      ^Thinking it over, you step back.";
                  }
                  print "Searching around the car, you ";
                  if (sparkPlugCar in self) "only find the spark plug on the radiator.";
                  "find nothing.";
              SwitchOn:
                  "The engine's being worked on. There's no way it's going to kick over.";
              SwitchOff:
                  "The engine's being worked on. It's already off.";
          ],
          firstTimeLook true,
          removeSparkPlug false,
     has  concealed static container open;

! 01/13/19

  ORchTV  gasStationComic "Conan comic"
    with  name 'conan' 'comic',
          before [;
              Buy:
                  "You gave it away. It's not for sale.";
              Examine:
                  if (gasStationJerry in gasStation)
                      "The attendant looks at the comic, almost mesmerized by the pictures.";
                  "The attendant left the comic behind in the booth.";
          ],
     has  concealed static;

! 01/09/20

  ORchTV  gasStationBottle "bottle"
    with  name 'coke' 'bottle' 'bottles' 'soda' 'pop',
          before [;
              Buy:
                  return PHP();
              Examine:
                  if (gasStationJerry in gasStation) {
                      if (iMinute > 40) "The attendant holds on to an empty bottle.";
                      "The attendant holds on to the coke bottle, drinking it occasionally.";
                  }
                  "Empty bottles start to fill the booth - the attendant drinking more than he should.";
          ],
     has  concealed static;
