
! ---------------------------------------------------------------------------- !
!       OUTSIDE POST OFFICE. 12/21/16
!
  Room    outsidePostOffice "Corner of Main & Ryders"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              if (rustyGate.dogBarking) {
                  print "The sound of a dog barking in the distance breaks the silence. ";
              } else {
                  if (SelfPlayer.dayStart || SelfPlayer.preMorning || SelfPlayer.morningTime || SelfPlayer.dayTime) {}
                  else { print "The hum of a street light breaks the silence. "; }
              }
              print "Maple Road becomes Main Street at this intersection, and Ryders Road shoots off south.
              A granite post office sits on the corner.";
              if (self.firstLook) {
                  self.firstLook = false;
                  print " Graffiti used to cover the building, but it's cleaned up.";
              }
              if (basement.firstTime) {
                  print " Main Street heads east to the town hall and west to a diner.
                  Ryders Road leads south to Madame Sorra's";
              } else {
                  print " Main Street heads east to the town hall and west towards the bowling alley.
                  Ryders Road leads south to Madame Sorra's";
              }
              if (self.infoDump) {
                  self.infoDump = false;
                  ".^^... Sam's been staying away from the mess by hanging out at the bar down at the
                  bowling alley. His wife blames you. Now that the landlord's found out you're all
                  living there, he's going to flip. You need to speak with Sam since
                  you can't talk to his wife.";
              }
              ".";
          ],
          e_to [;
              <<Enter outsidePostOfficeTownHall>>;
          ],
          w_to [;
              <<Enter outsidePostOfficeMapleRoad>>;
          ],
          s_to [;
              <<Enter outsidePostOfficeMadameSorras>>;
          ],
          n_to [;
              <<Enter outsidePostOfficeDoor>>;
          ],
          cant_go [;
              if (basement.firstTime)
                  "You can head east to the town hall, south to Madame Sorra's or west to the diner.";
              "You can head east to the town hall, south to Madame Sorra's or west towards the bowling alley.";
          ],
          before [;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (rustyGate.dogBarking) "A peaceful drone comes from the city around you, but it's broken by a dog barking in the distance.";
                  if (SelfPlayer.dayStart || SelfPlayer.preMorning || SelfPlayer.morningTime || SelfPlayer.dayTime) {
                      "A peaceful drone comes from the city around you. Other than that, it's quiet.";
                  }
                  "The hum from this light is louder than the others, breaking your concentration for a minute.";
              Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          infoDump true,
          seenFirstTime true,
          firstLook false,
          firstTime true;

! 12/21/16

  RoomObj -> outsidePostOfficeObj "Main Street"
    with  name 'area' 'street' 'main',
          description [;
              <<Look outsidePostOffice>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 12/21/16

  OutRch  -> outsidePostOfficeMapleRoad "Maple Road"
    with  name 'maple' 'gravel' 'road',
          before [;
              Enter, Go:
                  PlayerTo(mapleRoad);
                  rtrue;
              Examine:
                  "Maple Road continues west, turning into a gravel road.";
          ],
     has  proper;

! 12/22/16

  Object  -> outsidePostOfficePostOffice "post office"
    with  name 'post' 'office' 'building' 'place' 'granite',
          before [;
              Enter, Go:
                  <<Enter outsidePostOfficeDoor>>;
              Examine, Search:
                  if (basement.firstTime)
                      "The post office is a landmark made from granite. It's tagged with graffiti by kids with nothing better to do.";
                  "The post office is a landmark made from granite. An edifice made to last forever.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Open, Unlock:
                  if (second == shedKey) "You know better than to try.";
                  "You don't have a set of keys. You're not getting in.";
          ],
      has concealed static;

! 12/26/16

  Object  -> outsidePostOfficeDoor "door"
    with  name 'door' 'doors' 'window',
          before [;
              Examine, Search:
                  "The sign in the window reads closed.";
              Enter, Go:
                  "The post office is closed.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the post office.";
              Open, Unlock:
                  "You don't have a set of keys. You're not getting in.";
          ],
     has  concealed static;

! 12/26/16

  Object  -> outsidePostOfficeSign "sign"
    with  name 'sign',
          before [;
              Examine, Search:
                  "There's just one word on the sign: Closed. Nothing is written saying when the post office will open again.";
              default:
                  "You can't do that. It's behind the window.";
          ],
     has  concealed static;

! 12/23/16

  OutRch  -> outsidePostOfficeMadameSorras "Madame Sorra's"
    with  name 'madame' 'sorra' 'sorras' 'sorra^s' 'sorra?s' 'shop',
          before [;
              Enter, Go:
                  PlayerTo(outsideMadameSorras);
                  rtrue;
              Examine:
                  "Madame Sorra's shop lies down the road. It's a run-down building that's run by an old fortune-teller.";
          ],
     has  proper;

! 12/26/16

  OutRch  -> outsidePostOfficeTownHall "town hall"
    with  name 'town' 'hall',
          before [;
              Enter, Go:
                  PlayerTo(outsideTownHall);
                  rtrue;
              Examine:
                  if (basement.firstTime)
                      "The town hall is tagged with graffiti, like most of the other buildings in the area.
                      The village tries to clean it, but the kids just come back.";
                  "The town hall's another building that was once covered in graffiti.
                  Cleaned up, it looks like people take care of the area.";
          ];

! 07/05/19

  OutRch  -> outsidePostOfficeDiner "diner"
    with  name 'diner' 'restaurant' 'building' 'place',
          before [;
              Enter, Go:
                  <<Enter outsidePostOfficeMapleRoad>>;
              Examine:
                  "A diner sits off to the west. A small building that's open 24 hours.
                  You got food in there before, but it's always been too greasy.";
     ];

! 08/17/19

  OutRch  -> outsidePostOfficeLight "street light"
    with  name 'ph005642' 'ph005643' 'ph005644' 'ph005645',
          before [;
              Enter, Go:
                  "You are already here.";
              Examine:
                  "This light hums a little louder than the others. A sign it's starting to go.";
              Climb:
                  "Like a monkey, you think about shooting up the pole. But that's as far as you go.";
          ];

! 10/09/19

  ORchGr  -> outsidePostOfficeGraffiti "graffiti"
    with  name 'graffiti' 'tag' 'tags' 'name' 'names' 'colorful' 'mess',
          before [;
              Go, Enter:
                  "You are already here.";
              Examine:
                  "The post office is scrawled on and tagged with one name on top of another.";
              Read:
                  "It reads Sixx or Sexx. On top of it, cheap tags from the other kids try to cover it up.";
              Rub:
                  return PBT();
          ];

! 08/18/19

  OutRch  outsideLight "street light"
    with  name 'ph005642' 'ph005643' 'ph005644' 'ph005645',
          before [;
              Enter, Go:
                  "You are already here.";
              Climb:
                  "Like a monkey, you think about shooting up the pole. But that's as far as you go.";
              Examine:
                  if (SelfPlayer.eveningTime || SelfPlayer.earlyEvening)
                      "The street light tries to cut through dusk. The sound created by neon softly filling the city.";
                  "The street light illuminates from overhead. The sound created by neon softly filling the city.";
          ],
          found_in gravelRoad outsideMadameSorras outsideArtGallery outsideJoesBar outsideComplex
          outsideStore outsideLibrary outsideTownHall busStop;
