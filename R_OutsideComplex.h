
! ---------------------------------------------------------------------------- !
!       OUTSIDE COMPLEX. 12/29/16
!
  Room    outsideComplex "Corner of South & Midland"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              print "Highland Towers sits on the corner. A large and looming apartment complex. ";
              if (basement.firstTime) print "It was once an upscale joint but has been neglected over time. ";
              print "South Street runs west to The Tavern";
              if (theTavern.closedUp == false) print ", a bar that's playing music too loud";
              print ". North along Midland Drive, a convenience store is tucked in amongst some duplexes";
              if (basement.firstTime) {
                  if (outsideComplexDoor.cigOut) print ".^^A doorman stands outside the building";
                  else print ".^^A doorman stands outside smoking a cigarette";
              }
              else print ".^^A doorman that knows his tenants stands outside the building";
              if (dollarBill in self) {
                  move dollarBill to outsideStore;
                  print ".^^The wind picks up a dollar bill sitting in the middle of the street, blowing it north";
              }
              ".";
          ],
          n_to [;
              <<Enter outsideComplexStore>>;
          ],
          s_to [;
              <<Enter outsideComplexDoor>>;
          ],
          w_to [;
              <<Enter outsideComplexJoesBar>>;
          ],
          cant_go [;
              "You can go north to the store or west to the bar.";
          ],
          before [;
              GoIn:
                  <<Enter outsideComplexDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (theTavern.closedUp == false) "Rock music can be heard in the street, coming from a bar that's playing it too loudly.";
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sorry:
                  <<Answer t_sorry outsideComplexDoorman>>;
              Wave:

              Yes:
                  <<Answer t_yes outsideComplexDoorman>>;
              No:
                  <<Answer t_no outsideComplexDoorman>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true;

! 12/29/16

  RoomObj -> outsideComplexObj "South Street"
    with  name 'area' 'street' 'road' 'south',
          description [;
                    <<Look outsideComplex>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 12/29/16

  Object  -> outsideComplexComplex "complex"
    with  name 'complex' 'building' 'place' 'high-rise' 'highrise' 'high' 'rise' 'highland' 'towers' 'tower' 'apartment' 'apartments' 'paint' 'balconies' 'balcony' 'clutter',
          before [;
              Enter:
                  <<Enter outsideComplexDoor>>;
              Examine, Search:
                  if (basement.firstTime) {
                      if (outsideComplexDoor.cigOut)
                          "At the entrance stands a doorman not paying much
                          attention to anything. Above him, the balconies are
                          cluttered - and the paint on the building peels away.";
                      "At the entrance stands a doorman smoking a cigarette and
                      not paying much attention to anything. Above him, the balconies
                      are cluttered - and the paint on the building peels away.";
                  }
                  "At the entrance of the place stands a doorman, keeping his eye on you.
                  Above him, the balconies are organized - and the paint on the building looks fresh.";
              Rub:
                  if (basement.firstTime) "It would take forever to clean the building. You don't have the time to do that.";
                  "You don't have the time to do that.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
      has concealed static;

! 12/29/16

  Object  -> outsideComplexDoor "door"
    with  name 'door' 'doors' 'entrance',
          before [;
              Examine, Search:
                  "The doors are open with a doorman standing next to them.";
              Enter:
                  if (self.cigOut) "You try to step inside. The doorman stops you, ~Look. You don't live here.~";
                  self.cigOut = true;
                  if (basement.firstTime)
                      "The doorman stops you, putting his cigarette out on the ground. ~You don't live here.~";
                  "The doorman stops you, ~You don't live here.~";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the complex.";
          ],
          cigOut false,
     has  concealed static;

! 12/29/16

  OutRch  -> outsideComplexJoesBar "bar"
    with  name 'tavern' 'bar' 'ph002876',
          before [;
              Enter, Go:
                  PlayerTo(outsideJoesBar);
                  rtrue;
              Examine:
                  if (theTavern.closedUp == false) "Loud rock music pours out of a bar that sits at the entrance of a subdivision.";
                  if (basement.firstTime)
                      "The bar has been closed now for almost a year. You never got over there,
                      but it's still a shame they had to shut down.";
                  "The bar sits at the entrance of a subdivision closed. It's quiet out here.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 12/29/16

  OutRch  -> outsideComplexStore "store"
    with  name 'convenience' 'store' 'mart',
          before [;
              Enter, Go:
                  PlayerTo(outsideStore);
                  rtrue;
              Examine:
                  if (currentTime())
                      "It's slow right now over at the convenience store. No one's coming or going,
                      but you're sure that'll change.";
                  print "No one is coming or going out of the convenience store";
                  if (self.lookAtFirstTime) {
                      self.lookAtFirstTime = false;
                      outsideLibraryStore.lookAtFirstTime = false;
                      ". Strange, the mart is always busy.";
                  }
                  ".";
          ],
          lookAtFirstTime true;

! 01/24/18

  OutRch  -> outsideComplexDuplexes "duplexes"
    with  name 'duplex' 'duplexes',
          before [;
              Enter:
                  "They're north over by the store.";
              Go:
                  PlayerTo(outsideStore);
                  rtrue;
              Examine:
                  "Duplexes line Midland Drive. The stoops are small, so nothing is left outside.";
          ],
    has   pluralname;

! 07/02/19

  Class  ORchCom
   with  before [;
             if (outsideComplexDoor.cigOut) "It's just a cigarette butt. There's no reason to mess with it.";
             "The doorman wouldn't appreciate that.";
         ];

! 07/02/19

  ORchCom -> outsideComplexCigarettes "cigarette"
    with  name 'cigarettes' 'cigarette' 'cig' 'cigs' 'fag' 'fags',
          before [;
              Buy:
                  if (outsideComplexDoor.cigOut) "That's garbage and not for sale.";
                  "~Get out of here, I'm not selling ya' one.~";
              Examine:
                  if (outsideComplexDoor.cigOut) "The butt of the cigarette has been put out on the ground.";
                  "The doorman takes a drag off it every now and then.";
              Take:
                  if (outsideComplexDoor.cigOut) "~Look. Leave the trash alone and get out of here.~";
                  if (self.triedToTake) "You think twice before deciding against it.";
                  self.triedToTake = true;
                  "The doorman pushes you back, ~you better watch it. You don't know who you're messing with.~";
          ],
          triedToTake false,
     has  concealed static;

  Include "NPC_Doorman";

! 06/02/20

  OutRch  outsideComplexSubdivision "subdivision"
    with  name 'subdivision' 'homes' 'home' 'house' 'sub',
          before [;
              Enter, Go:
                  PlayerTo(outsideJoesBar);
                  rtrue;
              Examine:
                  "Tucked away on the south side of the town sits the subdivision. Full of middle-class homes and spoiled families.";
          ],
          found_in outsideComplex outsideArtGallery;
