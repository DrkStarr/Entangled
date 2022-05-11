! In the back of the bar is a kitchen attached to an alley.  The player has to
! put the FROB in the dumpster, then go back into the bar, raising no susppion.
! If they go outside and leave with the FROB, the owner of the bar will lock things
! up and go home. Closing off the bar.
!

! A shaddy place for its location.

! ---------------------------------------------------------------------------- !
!       OUTSIDE JOE'S BAR. 12/28/16'
!
  Room    outsideJoesBar "South Street"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              iAskWait = 0;
              SelfPlayer.outside = true;
              theTavernDoor.bartenderReturns = true;
              artGallery.curatorOutside = true;
              if (currentTime()) {
                  print "South Street sits on the edge of a subdivision. The bar on the corner ";
                  if (self.seenBarClosed) {
                      self.seenBarClosed = false;
                      print "has been closed now for almost a year";
                  } else {
                      print "is closed";
                  }
                  ". The road runs east to west with a high-rise to the east and a tattoo shop
                  to the west.";
              }
              print "South Street sits on the edge of a subdivision with a small bar on the corner.
              The Tavern.";
              if (theTavern.closedUp == false) print " Music beats its way into the street.";
              print " The road runs east to west with a high-rise to the east and an art gallery to
              the west";
              if (theTavern.closedUp == false) print ". You can also enter the bar to the south";
              if (dollarBill in self) {
                  StartDaemon(dollarBill);
                  move dollarBill to outsideComplex;
                  print ".^^The wind picks up a dollar bill sitting in the middle of the street, blowing it east";
              }
              if (theTavernHarry in self) {
                  StopDaemon(theTavernHarry);
                  iWait = 0;
                  remove theTavernHarry;
                  if (theTavern.theTavernEntered) {
                      ".^^The old guy from the bar sneers at you as he watches you leave.
                      Turning, he enters the subdivision to the south. Slowly he makes his
                      way through the streets before entering one of the homes.";
                  } else {
                      ".^^An old guy exits the bar, walking around the corner and entering the subdivision to the
                      south. Slowly he makes his way through the streets before entering one
                      of the homes.";
                  }
              }
              theTavern.theTavernEntered = false;
              ".";
          ],
          s_to [;
              <<Enter outsideJoesBarDoor>>;
          ],
          e_to [;
              <<Enter outsideJoesBarComplex>>;
          ],
          w_to [;
              if (basement.firstTime) <<Enter outsideJoesBarTattooShop>>;
              <<Enter outsideJoesBarArtGallery>>;
          ],
          cant_go [;
              if (currentTime()) "You can head east to an apartment complex or west to a tattoo shop.";
              if (theTavern.closedUp == false) "You can head east to an apartment complex, west to an art gallery, or south into the bar.";
              "You can head east to an apartment complex or west to an art gallery.";
          ],
          before [;
              GoIn:
                  <<Enter outsideJoesBarDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (theTavern.closedUp == false) "Loud rock music from the bar floods the street.";
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Wave:

              Yes:
                  if (theTavernHarry in outsideJoesBar) <<Answer t_yes theTavernHarry>>;
              No:
                  if (theTavernHarry in outsideJoesBar) <<Answer t_no theTavernHarry>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          seenBarClosed true;

! 12/28/16

  RoomObj -> outsideJoesBarObj "South Street"
    with  name 'area' 'street' 'streets' 'road' 'south',
          description [;
              <<Look outsideJoesBar>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 12/28/16

  Object  -> outsideJoesBarBar "bar"
    with  name 'tavern' 'bar' 'building' 'sign' 'place' 'window',
          before [;
              Enter, Go:
                  <<Enter outsideJoesBarDoor>>;
              Examine, Search:
                  if (basement.firstTime) {
                      print "They left the sign up for some reason. It reads, ~The Tavern.~ Looking through the bar's window, you see ";
                  } else {
                      print "Above the door, the sign reads, ~The Tavern.~ Looking through the window, you see ";
                  }
                  if (theTavern.closedUp) {
                      if (basement.firstTime) "the lights are off and the place has been gutted. Nothing is left but a few chairs.";
                      "an empty bar.";
                  }
                  if (theTavernHarry in theTavern) "one person sitting at the bar, drinking. The bartender stands around.";
                  if (theTavernNick in theTavern) "a bartender standing around.";
                  "an empty bar.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Open, Unlock:
                  if (theTavern.closedUp) "You don't have a set of keys. You're not getting in.";
          ],
     has  concealed static;

! 12/28/16

  Object  -> outsideJoesBarDoor "doors"
    with  name 'door' 'doors' 'board' 'boards',
          before [;
              Close:
                  if (theTavern.closedUp) {
                      if (basement.firstTime) "The doors are boarded up. You can't do that.";
                      "The bar's closed and the doors are locked.";
                  }
                  "You don't need to do that.";
              Open:
                  if (theTavern.closedUp) {
                      if (basement.firstTime) "The doors are boarded up. You can't do that.";
                      "You don't have a set of keys. You're not getting in.";
                  }
                  "The doors are already open.";
              Examine, Search:
                  if (theTavern.closedUp) {
                      if (basement.firstTime) "Boards cover the door, preventing anyone from entering.";
                      "The doors are closed, the bar's locked up.";
                  }
                  "The doors to the place are open.";
              Enter:
                  if (theTavern.closedUp) {
                      if (basement.firstTime) "You can see the doors are boarded up. You're not getting in.";
                      "It's late, the bar's closed.";
                  }
                  PlayerTo(theTavern);
                  rtrue;
              Take, Remove:
                  if (basement.firstTime) "You tug on them for a bit, but flesh gives way to wood. They won't budge.";
                  "You can't do that. They're part of the bar.";
              Turn:
                  "You can't do that. They're part of the bar.";
              Pull:
                  if (basement.firstTime) "You tug on them for a bit, but flesh gives way to wood. They won't budge.";
                  "You can't do that. They're part of the bar.";
              PushDir, Push:
                  if (basement.firstTime) "You try to push them, but they won't budge.";
                  "You can't do that. They're part of the bar.";
              Unlock:
                  if (theTavern.closedUp) {
                      if (basement.firstTime) "The doors are boarded up. You can't do that.";
                      if (second == shedKey) "You know better than to try.";
                      "You don't have a set of keys. You're not getting in.";
                  }
                  "The doors are already open.";
          ],
     has  concealed static pluralname;

! 06/17/19

  OutRch  -> outsideJoesBarTattooShop "tattoo shop"
    with  name 'tatto' 'shop',
          before [;
              Enter, Go:
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Examine:
                  "The lights to the tattoo shop are on, so it should be open.";
          ];

! 12/28/16

  OutRch  -> outsideJoesBarComplex "complex"
    with  name 'apartment' 'complex' 'high-rise' 'high' 'rise' 'building' 'tower' 'towers' 'highland',
          before [;
              Enter, Go:
                  PlayerTo(outsideComplex);
                  rtrue;
              Examine:
                  "It's a high-rise complex that has a doorman watching over the place.";
          ];

! 8/07/20

  OutRch  -> outsideJoesBarDoorman "doorman"
    with  name 'doorman',
          before [;
              Enter, Go:
                  PlayerTo(outsideComplex);
                  rtrue;
              Examine:
                  "The doorman stands in front of the complex, looking out for trouble.";
          ],
      has animate;

! 12/28/16

  OutRch  -> outsideJoesBarSubdivision "subdivision"
    with  name 'subdivision' 'homes' 'home' 'house' 'sub',
          before [;
              Enter, Go:
                  "The people that live there don't like strangers around.";
              Examine:
                  "Tucked away on the south side of the town sits the subdivision, full of middle-class homes
                  and spoiled families.";
          ];

! 12/28/16

  OutRch  outsideJoesBarArtGallery "art gallery"
    with  name 'art' 'gallery',
          before [;
              Enter, Go:
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Examine:
                  "No one is going in or out of the gallery, but the lights are on, so it should be open.";
          ];

! 10/24/18

  Object  outsideJoesBarPerson "person"
    with  name 'old' 'man' 'oldman' 'oldguy' 'guy' 'harry' 'patron' 'person',
          describe [;
              rtrue;
          ],
          before [;
              Enter, Go:
                  PlayerTo(theTavern);
                  rtrue;
              Examine:
                  "An older man sits with his back to you, drinking while talking to the bartender.";
              WaveObject:
                  "The older man doesn't see you. His back is to you.";
              default:
                  "You can't do that from here.";
          ],
          life [;
              "You can't do that from here.";
          ],
          orders [;
              "You can't do that from here.";
          ],
    has   animate male concealed scenery;

! 10/24/18

  Object  outsideJoesBarBartender "bartender"
    with  name 'nick' 'bartender' 'dude' 'pretty' 'boy' 'man' 'guy',
          describe [;
              rtrue;
          ],
          before [;
              Enter, Go:
                  PlayerTo(theTavern);
                  rtrue;
              Examine:
                  if (theTavernHarry in theTavern) "The bartender talks to an older man. Who sits there nursing a drink.";
                  "The bartender is alone and wipes down the bar now and then.";
              WaveObject:
                  if (theTavernHarry in theTavern) "He doesn't seem to notice you talking to the person at the bar.";
                  "He doesn't seem to notice you as he wipes down the bar.";
              default:
                  "You can't do that from here.";
          ],
          life [;
              "You can't do that from here.";
          ],
          orders [;
              "You can't do that from here.";
          ],
    has   animate male concealed;
