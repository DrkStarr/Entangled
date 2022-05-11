! Madame Sorra will not accept the gift from the PC if they've broken the crystal in the gallery.
!

! ---------------------------------------------------------------------------- !
!       OUTSIDE MADAME SORRA'S. 12/26/16
!
  Room    outsideMadameSorras "Ryders Road"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              iAskWait = 0;
              iAskRestless = 0;
              SelfPlayer.outside = true;
              artGallery.curatorOutside = true;
              print "In the middle of a row of buildings sits a structure that looks like it's going to fall in on itself";
              if (madameSorrasSign.signOn) print ". It welcomes you in with a pink neon sign - a handprint behind the window";
              else print ". Behind the window, the neon sign of the handprint is off";
              print ". Written above the doorbell is the name Sorra.
              Ryders Road heads north to the post office and south to ";
              if (currentTime()) "the tattoo shop.";
              "an art gallery.";
          ],
          n_to [;
              <<Enter outsideMadameSorrasPostOffice>>;
          ],
          w_to [;
              <<Enter outsideMadameSorrasDoor>>;
          ],
          s_to [;
              if (currentTime()) <<Enter outsideMadameSorrasTattooShop>>;
              <<Enter outsideMadameSorrasArtGallery>>;
          ],
          cant_go [;
              if (currentTime()) "You can head north to the post office, south to the tattoo shop or west into Madame Sorras.";
              "You can head north to the post office, south to the art gallery or west into Madame Sorras.";
          ],
          before [;
              GoIn:
                  <<Enter outsideMadameSorrasDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  print "A peaceful drone comes from the city around you";
                  if (rustyGate.dogBarking) ", but it's broken by the faint sound of a dog barking in the distance.";
                  ". Other than that, it's quiet.";
              Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          firstTime true;

! 12/26/16

  RoomObj -> outsideMadameSorrasObj "Ryders Road"
    with  name 'area' 'street' 'road' 'ryders',
          description [;
                    <<Look outsideMadameSorras>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 12/26/16

  OutRch  -> outsideMadameSorrasPostOffice "post office"
    with  name 'post' 'office',
          before [;
              Enter, Go:
                  PlayerTo(outsidePostOffice);
                  rtrue;
              Examine:
                  if (currentTime())
                      "The post office across the street is a granite building made to last forever. Too bad it's been tagged with graffiti.";
                  "The post office across the street is a granite building made to last forever. It's also closed.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
      has concealed static;

! 12/28/16

  OutRch  -> outsideMadameSorrasTattooShop "tattoo shop"
    with  name 'tattoo' 'shop',
          before [;
              Enter, Go:
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Examine:
                  "No one seems to be going in or out of the tattoo shop, but the lights are on, so it should be open.";
          ];

! 12/26/16

  Object  -> outsideMadameSorrasDoor "door"
    with  name 'door' 'doors',
          before [;
              Examine, Search:
                  "The door to the place is decrepit like the rest of the building.";
              Enter, Go, Open:
                  if (madameSorrasMadameSorra in madameSorras) {
                      print "(first ringing the doorbell)^
                      Madame Sorra opens the door, ~Please. Come in.~^";
                  } else {
                      if (oldMadameSorra in madameSorras) {
                          print "(first ringing the doorbell)^
                          After a bit, Madame Sorra opens the door, ~Please. Come in.~^";
                      } else {
                          print "Since no one is home, you let yourself in.^";
                      }
                  }
                  PlayerTo(madameSorras);
                  rtrue;
              Knock:
                  print "You decide to ring the bell instead.^^";
                  <<Push outsideMadameSorrasBell>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the building.";
          ],
     has  concealed static;

! 12/26/16

  Object  -> outsideMadameSorrasBuilding "building"
    with  name 'decrepit' 'building' 'paint' 'place' 'sorra^s' 'sorra?s' 'sorras' 'outer' 'shell' 'ph0402',
          before [;
              Examine, Search:
                  "Time has not been kind to this building. Over the years, the sun has cooked
                  the frame as its outer shell peeled away. No one has put a fresh coat of
                  paint on in a long time.";
              Enter, Go:
                  <<Enter outsideMadameSorrasDoor>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  concealed static;

! 12/26/16

  Object  -> outsideMadameSorrasSign "sign"
    with  name 'neon' 'sign' 'hand' 'palm' 'print' 'window' 'handprint',
          before [;
              Examine, Search:
                  if (madameSorrasSign.signOn) "The neon sign is shaped like a hand, letting customers know there's a fortune teller inside.";
                  "The neon sign is off, and everyone knows what it means. The Madame is out.";
              default:
                  "You can't do that. It's behind a window.";
          ],
     has  concealed static;

! 12/26/16

  Object  -> outsideMadameSorrasBell "bell"
    with  name 'doorbell' 'bell' 'name' 'nameplate' 'sorra',
          before [;
              Examine, Search:
                  "The doorbell sits under a nameplate that reads ~Sorra.~";
              Push:
                  if (madameSorrasMadameSorra in madameSorras) {
                      print "A faint ring comes from inside.
                      A moment later, Madame Sorra opens the door, ~Please. Come in.~^";
                  } else {
                      if (oldMadameSorra in madameSorras) {
                          print "A faint ring comes from inside.
                          After a bit, Madame Sorra opens the door, ~Please. Come in.~^";
                      } else {
                          print "You push the doorbell, but no one answers. You let yourself in.^";
                      }
                  }
                  PlayerTo(madameSorras);
                  rtrue;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the door.";
          ],
     has  concealed static;

! 04/23/20

  ORchGr  -> outsideMadameSorrasGraffiti "graffiti"
    with  name 'graffiti' 'tag' 'tags' 'name' 'names' 'colorful' 'mess',
          before [;
              Go, Enter:
                  <<Enter outsideMadameSorrasPostOffice>>;
              Examine, Read:
                  "It's too hard to read from here. You only see a colorful mess.";
          ];

! 12/28/16

  OutRch  outsideMadameSorrasArtGallery "art gallery"
    with  name 'art' 'gallery',
          before [;
              Enter, Go:
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Examine:
                  "No one seems to be going in or out of the gallery, but the lights are on, so it should be open.";
          ];
