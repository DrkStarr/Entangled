
! ---------------------------------------------------------------------------- !
!       OUTSIDE ART GALLERY. 12/28/16
!
  Room    outsideArtGallery "Corner of South & Ryders"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              iAskGo=0;
              iRepeat=0;
              iAskStay=0;
              SelfPlayer.outside = true;
              if (currentTime()) {
                  "On this corner sits the Crazy Monkey. A tattoo shop run by an old biker.
                  The lights are on, and Nick is always happy to see people in his place.
                  Ryders Road heads north to Madame Sorra's. South Street runs east to a bar.^
                  ^An alley lies to the southwest and runs alongside the shop.";
              }
              print "On this corner sits the South Street Gallery with a symbol of a tree painted
              on the door. Lights are on inside. It looks open though no one is around.
              Ryders Road heads north to Madame Sorra's. South Street runs east to The Tavern.^";
              if (backAlley.curatorLeaving) "^From the southwest, you can hear the curator curse to herself in the alley.";
              "^An alley lies to the southwest and runs alongside the gallery.";
          ],
          n_to [;
              <<Enter outsideArtGalleryMadameSorras>>;
          ],
          s_to [;
              if (currentTime()) <<Enter outsideArtGalleryTattooShop>>;
              <<Enter outsideArtGalleryDoor>>;
          ],
          e_to [;
              <<Enter outsideArtGalleryJoesBar>>;
          ],
          sw_to [;
              <<Enter outsideArtGalleryAlley>>;
          ],
          cant_go [;
              if (currentTime()) "You can head north to Madame Sorra's. South to the tattoo shop. East to the bar or southwest down the alley.";
              "You can head north to Madame Sorra's. South to the gallery. East to The Tavern or southwest down the alley.";
          ],
          before [;
              GoIn:
                  if (currentTime()) <<Enter outsideArtGalleryTattooShop>>;
                  <<Enter outsideArtGalleryDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (backAlley.stillHearGallery) {
                      if (theTavern.closedUp) "The curator curses to herself, breaking the still of the night.";
                      "You can hear the curator curse to herself from the ally, over the loud music coming from the bar.";
                  }
                  if (backAlley.curatorLeaving) {
                      if (theTavern.closedUp) "The curator curses to herself, breaking the still of the night.";
                      "You can hear the curator curse to herself from the ally, over the loud music coming from the bar.";
                  }
                  if (theTavern.closedUp == false) "Rock music can be heard in the street, coming from a bar that's playing it too loudly.";
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          firstTime true;

! 12/28/16

  RoomObj -> outsideArtGalleryObj "South Street"
    with  name 'area' 'street' 'road' 'south',
          description [;
              <<Look outsideArtGallery>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 12/28/16

  OutRch  -> outsideArtGalleryMadameSorras "Madame Sorra's"
    with  name 'madame' 'sorra' 'sorras' 'sorra^s' 'sorra?s',
          before [;
              Enter, Go:
                  PlayerTo(outsideMadameSorras);
                  rtrue;
              Examine:
                  "Madame Sorra's lies across the street to the north, run by an old fortune-teller.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
           has  proper;

! 12/28/16

  OutRch  -> outsideArtGalleryJoesBar "bar"
    with  name 'tavern' 'bar' 'ph002876',
          before [;
              Enter, Go:
                  PlayerTo(outsideJoesBar);
                  rtrue;
              Examine:
                  if (currentTime())
                      "The bar has been closed now for almost a year. You never got over there,
                      but it's still a shame they had to shut it down.";
                  print "A bar sits at the entrance of a subdivision";
                  if (theTavern.closedUp) ".";
                  " with music that can be heard out here in the street.";
          ];

! 01/17/18

  OutRch  -> outsideArtGalleryAlley "alley"
    with  name 'alley',
          before [;
              Enter, Go:
                  PlayerTo(backAlley);
                  rtrue;
              Examine:
                  if (currentTime()) "The alley is southwest of here and runs alongside the shop.";
                  "The alley is southwest of here and runs alongside the gallery.";
          ];

! 06/03/19

  Object  -> outsideArtGalleryTattooShop "tattoo shop"
    with  name 'tattoo' 'building' 'place' 'shop' 'lights' 'crazy' 'monkey',
          before [;
              Examine, Search:
                  "The Crazy Monkey is a tattoo shop that has been open since the '90s.
                  Run by an old biker, the place is usually open.";
              Enter, Go:
                  PlayerTo(tattooShop);
                  rtrue;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          firstTimeLooked false,
     has  concealed static;

! 05/25/20

  Object  -> outsideArtGalleryTattDoor "door"
    with  name 'door' 'doors' 'glass' 'paint',
          before [;
              Examine:
                  "It's all scratched up - like someone painted on it only to scrape it away in a half-hearted attempt.";
              Search:
                  "The glass has been painted over, and no one took the time to clean it properly.";
              Enter, Go, Open:
                  PlayerTo(tattooShop);
                  rtrue;
              Knock:
                  "You hear someone say, ~come in,~ from the inside." ;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gallery.";
              Rub:
                  "It would take a razor blade to get that off.";
          ],
     has  concealed static;

! 10/06/19

  OutRch  -> outsideArtGalleryMeteor "meteor"
    with  name 'meteor' 'ufo' 'ufos' 'shower' 'fireball' 'fireballs',
          before [;
              Examine:
                  return MLookUp();
              Follow:
                  "You're not in a rocket.";
              Enter, Go:
                  "You'd need a rocket to get up there.";
          ];

! 12/28/16

  Object  outsideArtGalleryDoor "door"
    with  name 'door' 'doors' 'glass',
          before [;
              Examine:
                  "The door is painted with an intricate symbol of a tree.";
              Search:
                  "The painting of the tree makes it hard to see through the glass.";
              Enter, Go, Open:
                  PlayerTo(artGallery);
                  rtrue;
              Knock:
                  print "The place looks open, so you decide to enter.^";
                  PlayerTo(artGallery);
                  rtrue;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gallery.";
          ],
      has concealed static;

! 12/28/16

  Object  outsideArtGalleryGallery "gallery"
    with  name 'art' 'gallery' 'building' 'place' 'shop' 'light' 'lights' 'store',
          before [;
              Examine, Search:
                  return (PrintExamineArtGallery());
              Enter, Go:
                  <<Enter outsideArtGalleryDoor>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          firstTimeLooked false,
     has  concealed static;

  [ PrintExamineArtGallery;
        "The gallery's coated in stucco painted a light beige. Strange words have been drawn
        across the top encircling the building.";
  ];

! 12/28/16

  Object  outsideArtGallerySymbol "symbol"
    with  name 'symbol' 'tree' 'root' 'roots' 'intricate' 'painting' 'painted',
          before [;
              Examine, Search:
                  "It's a large tree with deep roots reminding you of the Tree of Life.";
              default:
                  "You can't do that. It's painted on the glass.";
          ],
     has  concealed static;

! 12/28/16

  OutRch  outsideArtGalleryWords "words"
    with  name 'strange' 'word' 'words',
          before [;
              Examine, Search:
                  "The words look like a mix of Arabic, Egyptian, and Hebrew.";
              Read:
                  "You can't decipher their meaning.";
          ],
          found_in outsideArtGallery backAlley,
     has  concealed static pluralname;
