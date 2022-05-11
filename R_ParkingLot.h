
! ---------------------------------------------------------------------------- !
!       PARKING LOT. 08/10/16
!
  Room    parkingLot "Parking Lot"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              if (currentTime()) {
                  print "Muted colors display a mural on the front of the building.
                  Above, a bright neon sign blinks Lowry Lanes or at least tries to. The sign has been broken for years.
                  A few cars are in the parking lot";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime) print " tonight";
                  ". To the north is the bowling alley. South the dirt road.";
              }
              print "Bright colors display a mural on the side of the building.
              Above, a bright neon sign blinks Lowry Lanes";
              if (self.pastFirstTime) {
                  self.pastFirstTime = false;
                  print ". The letters are fixed";
              }
              print ". A few cars are in the parking lot";
              if (SelfPlayer.eveningTime || SelfPlayer.nightTime) print " tonight";
              ". To the north is the bowling alley. South the dirt road.";
          ],
          n_to [;
              <<Enter parkingLotBowlingAlley>>;
          ],
          s_to [;
              <<Enter parkingLotDirtRoad>>;
          ],
          cant_go [;
              "You can go north into the bowling alley or south to the dirt road.";
          ],
          before [;
              GoIn:
                  <<Enter parkingLotBowlingAlley>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  print "The buzz of the neon sign can be heard";
                  if (TestNight()) " as it cuts through the night.";
                  ".";
              Smell:
                  print "You take the rich autumn air into your lungs for a minute";
                  if (self.outOfAlley) ", glad to be out of the smoke.";
                  ".";
              Sleep:
                  return roomSleep();
          ],
          outOfAlley false,
          firstTime true,
          pastFirstTime true;

! 08/10/16

  RoomObj -> parkingLotObj "parking lot"
    with  name 'parking' 'lot' 'area',
          description [;
              <<Look parkingLot>>;
          ],
          before [;
              Search:
                  "It would take too long to search the area properly. Looking down at your feet, you
                  don't see anything out of the ordinary.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/10/16

  OutRch  -> parkingLotDirtRoad "dirt road"
    with  name 'dirt' 'road',
          before [;
              Enter, Go:
                  parkingLot.outOfAlley = false;
                  PlayerTo(dirtRoad);
                  rtrue;
              Examine:
                  "A dirt road leads out of the parking lot back to the city.";
          ];

! 12/10/19

  OutRch  -> parkingLotDoors "doors"
    with  name 'door' 'doors' 'double',
          before [;
              Enter, Go:
                  <<Enter parkingLotBowlingAlley>>;
              Examine:
                  "Double doors lead into the bowling alley.";
              Close, Open:
                  "They're automatic and don't work like that.";
          ];

! 08/10/16

  Object  -> parkingLotBowlingAlley "alley"
    with  name 'bowling' 'alley' 'building',
          before [;
              Enter, Go:
                  if (self.enterFirstTime) {
                      self.enterFirstTime = false;
                      if (plate in player) print "Stepping through the doors, a bright light flashes before your eyes and the plate you're holding onto vanishes.^";
                      else print "Stepping through the doors, a bright light flashes before your eyes.^";
                      print "^You feel a swaying motion. Then your stomach lurches. You look down at yourself.
                      Everything seems to be fine, but the bowling alley is different somehow.
                      Maybe cleaner. Brighter. Happier if that was even possible.^";
                  }
                  PlayerTo(bowlingAlley);
                  rtrue;
              Examine:
                  if (currentTime())
                      "A layer of grime covers the mural. The bright red and yellow of a ball shooting down a lane is now muted and pale.";
                  "Bright reds and yellows make a mural of a ball shooting down a lane crashing into pins.";
              Climb:
                  print "There's no easy way to get to the roof";
                  if (currentTime()) ". That's probably why the owner hasn't fixed the sign yet.";
                  ".";
              Rub:
                  if (currentTime()) "You don't have time to do that. It's just too big to clean.";
                  "It doesn't need to be cleaned.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          enterFirstTime true,
     has  concealed static;

! 09/21/20

  Object  -> parkingLotMural "mural"
    with  name 'color' 'colors' 'gaudy' 'red' 'reds' 'yellow' 'yellows' 'pin' 'pins' 'mural' 'place' 'layer' 'grime' 'muted' 'pale' 'front' 'display' 'wall',
          before [;
              Enter, Go:
                  "You're already here.";
              Examine:
                  <<Examine parkingLotBowlingAlley>>;
              Climb:
                  <<Climb parkingLotBowlingAlley>>;
              Rub:
                  <<Rub parkingLotBowlingAlley>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
           has  concealed static;

! 08/16/16

  OutRch  -> parkingLotNeonSign "neon sign"
    with  name 'bright' 'neon' 'sign' 'lowry' 'lanes' 'broken',
          before [;
              Climb:
                  "It's not that simple. There's no way to get to the roof.";
              Examine, Read:
                  if (currentTime())
                      "That sign has been up there for ages. It's too bad some kids
                      had to knock out the ~O~ and ~R.~ The owner's talked about fixing
                      it, but he's done nothing.";
                  print "All the letters work, blinking away on their own. The sign is fixed and reads Lowry Lanes";
                  if (self.seenSignPast) ".";
                  self.seenSignPast = true;
                  ". Something happened when you walked through the door.";
          ],
          seenSignPast false;

! 12/21/16

  Object  -> parkingLotCars "cars"
    with  name 'car' 'cars' 'vehicle' 'vehicles' 'truck' 'trucks' 'jeep' 'jeeps' 'trunk',
          before [;
              Attack, Open:
                  "The parking lot is wide open. You don't want to be seen breaking into a vehicle.";
              Examine, Search:
                  if (currentTime())
                      "The few cars in the lot are beaters - older vehicles driven into the ground.";
                  "The few cars that are out here are a bit dated but in good condition.";
              Enter:
                  "Are you going to steal one? You don't need that kind of hassle.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The cars don't need to go anywhere.";
          ],
     has  concealed static pluralname;

! 01/13/19

  Object  -> parkingLotHoods "hoods"
    with  name 'hood' 'hoods',
          before [;
              Examine:
                  <<Examine parkingLotCars>>;
              Open, Search, Enter, Go:
                  "Someone would see you working on it for sure, and then they'd come over to help.
                  It wouldn't take long for them to find out it isn't your car and you'd be in all
                  sorts of trouble.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The cars don't need to go anywhere.";
          ],
     has  concealed static pluralname;

! 05/14/18

  OutRch  -> parkingLotRoof "roof"
    with  name 'roof' 'flat-top',
          before [;
              Enter, Go:
                  "You'd have to climb, but there's no ladder.";
              Climb:
                  "It's not that simple. There's no way to get to the roof.";
              Examine:
                  "You know it's a flat-top roof, but you can't even see it from here.";
          ];
