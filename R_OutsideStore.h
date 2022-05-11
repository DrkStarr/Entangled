
! ---------------------------------------------------------------------------- !
!       OUTSIDE CONVENIENCE STORE. 1/2/17
!
  Room    outsideStore "Midland Drive"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              convenienceStore.walkIn = true;
              if (convenienceStoreMelGone in convenienceStore) remove convenienceStoreMelGone;
              print "For being open 24 hours a day, no one's around the convenience store - ";
              if (currentTime()) {
                  print "a building covered in ads for beer and cigarettes";
              } else {
                  print "a building that used to be covered in ads for beer. It's now cleaned up";
              }
              print ". Lined with duplexes, Midland Drive runs north and south.
              North the library is set off the street. South Highland Towers looms over
              the city. You can also go into the store";
              if (dollarBill in self) {
                  move dollarBill to outsideLibrary;
                  print ".^^The wind picks up a dollar bill sitting in the middle of the street, blowing it north";
              }
              if (self.followKid) {
                  self.followKid = false;
                  print ".^^The kid is nowhere to be found";
              }
              ".";
          ],
          n_to [;
              <<Enter outsideStoreLibrary>>;
          ],
          e_to [;
              <<Enter outsideStoreDoor>>;
          ],
          s_to [;
              <<Enter outsideStoreComplex>>;
          ],
          cant_go [;
              "You can head north to the library, south to the apartment complex or east into the store.";
          ],
          before [;
              GoIn:
                  <<Enter outsideStoreDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          followKid false;

! 1/10/17

  RoomObj -> outsideStoreObj "Midland Drive"
    with  name 'area' 'street' 'road' 'midland' 'drive',
          description [;
              <<Look outsideStore>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 1/10/17

  Object  -> outsideStoreStore "store"
    with  name 'convenience' 'store' 'shop' 'building' 'place',
          before [;
              Enter, Go:
                  <<Enter outsideStoreDoor>>;
              Examine, Search:
                  if (currentTime())
                      "The store's covered in ads. They pasted one on top of another.
                      There's no graffiti on the building, but if it was tagged, it's
                      covered by an ad.";
                  "The store used to have ads all over it, making it a big advertisement.
                  But now there's only one for beer at $3.49 a six-pack.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
      has concealed static;

! 1/10/17

  Object  -> outsideStoreDoor "door"
    with  name 'door' 'doors',
          before [;
              Close:
                  "You don't need to do that.";
              Examine, Search:
                  if (currentTime()) "Stickers and ads cover the door.";
                  "The door to the convenience store is closed.";
              Enter, Go, Open:
                  PlayerTo(convenienceStore);
                  rtrue;
              Read:
                  if (currentTime()) <<Read outsideStoreAds>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the store.";
          ],
      has concealed static;

! 1/10/17

  OutRch  -> outsideStoreComplex "complex"
    with  name 'apartment' 'complex' 'high-rise' 'high' 'rise' 'building' 'highland' 'tower' 'towers',
          before [;
              Enter, Go:
                  PlayerTo(outsideComplex);
                  rtrue;
              Examine:
                  "It's a high-rise complex that has a doorman watching over the place.";
          ];

! 8/07/20

  OutRch  -> outsideStoreDoorman "doorman"
    with  name 'doorman',
          before [;
              Enter, Go:
                  PlayerTo(outsideComplex);
                  rtrue;
              Examine:
                  "The doorman stands in front of the complex, looking out for trouble.";
          ],
      has animate;

! 1/10/17

  OutRch  -> outsideStoreLibrary "library"
    with  name 'library' 'walkway' 'bench' 'benches',
          before [;
              Enter, Go:
                  PlayerTo(outsideLibrary);
                  rtrue;
              Examine:
                  if (currentTime())
                      "The library has been tagged, like all the buildings around here. It's set off the road and has a walkway lined with benches.";
                  "The library is set off the road and has a walkway lined with benches.";
          ];

! 07/13/20

  ORchGr  -> outsideStoreGraffiti "graffiti"
    with  name  'graffiti' 'tag' 'tags' 'name' 'names' 'colorful' 'mess',
          before [;
              Go, Enter:
                  PlayerTo(outsideLibrary);
                  rtrue;
              Examine, Read:
                  "It's too hard to read from here. You only see a colorful mess.";
          ];

! 01/24/18

  OutRch  -> outsideStoreDuplexes "duplexes"
    with  name 'duplex' 'duplexes' 'building',
          before [;
              Enter, Go:
                  "What do you think you're doing? People live here.";
              Examine:
                  "Duplexes line Midland Drive. The stoops are small, so nothing is left outside.";
          ],
    has   pluralname;

! 05/22/18

  Object  -> outsideStoreAds "ads"
    with  name 'ad' 'ads' 'cigarette' 'cigarettes' 'beer' 'stickers',
          before [;
              Examine, Read, Search:
                  if (currentTime())
                      "The ads have been plastered all over the place. They are probably covering graffiti, but they also make for one big advertisement.";
                  "There is one ad for some beer going for $3.49 a six-pack.";
              Take, Remove:
                  if (currentTime()) "They've been glued one on top of another. There's no way you could scrap them off.";
                  "It's glued to the door. You're not going to get it off.";
              Turn, PushDir, Push, Pull:
                  if (currentTime()) "There's no reason to mess with the ads.";
                  "There's no reason to mess with the ad.";
          ],
    has   concealed static pluralname;
