
! ---------------------------------------------------------------------------- !
!       EASTSIDE CLIFF. 08/05/16
!
  Room    cliff "Eastside Cliff"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              SelfPlayer.sawJerryLeave = false;
              "This cliff overlooks Sunnybrook, a small town that could be any one of a
              number of cities dotted across the Midwest. A path runs north and south.
              North down into town. South back to the trailer park.";
          ],
          n_to [;
              <<Enter cliffCity>>;
          ],
          d_to [;
              <<Enter cliffCity>>;
          ],
          s_to [;
              <<Enter cliffPark>>;
          ],
          cant_go [;
              "You can go north down into the city or south to the trailer park.";
          ],
          before [;
              Exit:

              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "A peaceful drone comes up from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Jump, JumpOver:
                  <<Enter cliffObj>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          seenFirstTime true,
          exitFirstTime true;

! 08/05/16

  RoomObj -> cliffObj "cliff"
    with  name 'cliff' 'area',
          description [;
              <<Look cliff>>;
          ],
          before [;
              Climb:
                  "That's a bit extreme. Why don't you try the path?";
              JumpOver, Enter, Go:
                  "You've thought about jumping before, you'd be lying to yourself to say otherwise, but that's no answer to your problems.";
              Search:
                  "You look around up here, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/05/16

  OutRch  -> cliffCity "town"
    with  name 'small' 'town' 'city' 'sunnybrook' 'sunny' 'brook' 'people' 'shadow' 'shadows' 'streets',
          before [;
              Enter, Go:
                  print "You walk down the path into town.^";
                  PlayerTo(gasStation);
                  rtrue;
              Examine:
                  if (currentTime()) {
                      if (SelfPlayer.dayStart)
                          "A burning red ball of fire sits above the town to the west as a thin haze covers everything
                          obscuring the people. Long shadows drift through the streets as they make their way home.";
                      if (SelfPlayer.dayTime || SelfPlayer.morningTime) {
                          "From up here, you watch people drift through the streets. They carry out their own business.";
                      }
                      if (SelfPlayer.eveningTime || SelfPlayer.preEvening || SelfPlayer.earlyEvening) {
                          "From up here, you watch the few left on the streets scurry home.";
                      }
                      "Street lights make a small grid outlining the town below. It doesn't look like
                      anybody is out tonight.";
                  }
                  if (self.firstTimeCliff) {
                      self.firstTimeCliff = false;
                      print "Looking down to the west, you can tell the smog you're used to seeing has lifted. ";
                  }
                  if (SelfPlayer.dayStart || SelfPlayer.dayTime || SelfPlayer.morningTime) {
                      "From up here, you watch people drift through the streets. They carry out their own business.";
                  }
                  if (SelfPlayer.eveningTime || SelfPlayer.preEvening || SelfPlayer.earlyEvening) {
                      "From up here, you watch the few left on the streets scurry home.";
                  }
                  "Street lights make a small grid outlining the town below. It doesn't look like
                  anybody is out tonight.";
          ],
          firstTimeCliff true;

! 08/11/16

  OutRch  -> cliffPark "trailer"
    with  name 'trailer' 'trailers' 'park' 'mess' 'clutter' 'lot' 'yard',
          before [;
              Enter, Go:
                  if (currentTime()) {
                      "Not without Sam.";
                  }
                  PlayerTo(trailerPark);
                  rtrue;
              Examine:
                  if (currentTime()) {
                      "Trailers are lined in rows. Clutter has built up around them. In front of the mess, a sign displays the park's name.";
                  } else {
                      if (self.examineObject)
                          "The park's been cleaned up. In front of it all, a sign proudly displays its name.";
                      self.examineObject = true;
                      "The garbage you used to see is gone. There's no clutter in the yard. The entire park looks like it's been cleaned up. In front of it all, a sign proudly displays its name.";
                  }
          ],
          examineObject false;

! 08/15/16

  OutRch  -> cliffRoad "path"
    with  name 'road' 'street' 'path',
          before [;
              Enter, Go, Climb:
                  "It goes in two directions. North or south.";
              Examine:
                  "The path up here runs from the trailer park down into the city.";
              Follow:
                  if (currentTime()) <<Enter cliffCity>>;
                  "It goes in two directions. North or south.";
          ];

! 08/15/16

  OutRch  -> cliffGarbage "garbage"
    with  name 'bag' 'bags' 'of' 'garbage',
          before [;
              Examine:
                  if (currentTime()) "You should've put the bags on the curb Thursday, but none of your neighbors will mind.";
                  "The garbage has been cleaned up, even the bags in front of your own place.";
              Take, Remove, Turn, PushDir, Push, Pull, Enter, Go:
                  if (currentTime()) "You had your chance. Waste Collection won't be around for another week.";
                  "The garbage has been cleaned up.";
          ];

! 05/07/18

  OutRch  -> cliffTrailerParkSign "sign"
    with  name 'sign',
          before [;
              Enter, Go:
                  if (currentTime()) {
                      "Not without Sam.";
                  }
                  PlayerTo(trailerPark);
                  rtrue;
              Climb, LookUnder:
                  "Not from here.";
              Examine, Read:
                  if (currentTime()) "In yellowing letters, written across fading stain, the sign reads Sunnybrook Trailer Park.";
                  "In big white letters, written across a dark brown background, the sign reads Sunnybrook Trailer Park.";
          ],
     has  concealed static;

! 05/07/18

  OutRch  -> cliffHome "home"
    with  name 'home' 'birdbath' 'busted' 'bath',
          before [;
              Enter, Go:
                  if (currentTime()) {
                      "Not without Sam.";
                  }
                  PlayerTo(trailerPark);
                  rtrue;
              Examine:
                  if (currentTime()) {
                      "Your trailer sits in the back. One of the cleaner ones on the lot even though it has a
                      busted birdbath in the front.";
                  } else {
                      "Your trailer should be the one in the back, but there's no birdbath in front of it.";
                  }
          ];

! 12/16/16

  OutRch  cliffSun "sun"
    with  name 'sun' 'sky' 'horizon' 'haze' 'fire' 'red' 'burning' 'ball' 'orange' 'hue',
          before [;
              Examine:
                  return PCliffSun();
          ],
          found_in cliff gasStation gravelRoad dirtRoad parkingLot backLot backYard outsidePostOffice
          outsideMadameSorras outsideArtGallery outsideJoesBar outsideComplex outsideStore outsideLibrary
          outsideTownHall busStop trailerPark smallPark rustyGate junkYard openField mapleRoad backAlley;

! 10/06/19

  OutRch  cliffMeteor "meteor"
    with  name 'meteor' 'ufo' 'lights' 'ufos' 'shower' 'fireball' 'fireballs',
          before [;
              Examine:
                  return MLookUp();
              Follow:
                  "You're not in a rocket.";
              Enter, Go:
                  "You'd need a rocket to get up there.";
          ],
          found_in cliff gasStation gravelRoad dirtRoad parkingLot backLot backYard outsidePostOffice
          outsideMadameSorras outsideJoesBar outsideComplex outsideStore outsideLibrary
          outsideTownHall busStop trailerPark smallPark rustyGate junkYard openField mapleRoad backAlley;

 [ PCliffSun;
       if (SelfPlayer.morningTime) "The soft glow of the sun warms a clear sky.";
       if (SelfPlayer.dayTime) "The sun beats down from above.";
       if (SelfPlayer.preEvening) "The bright red of the evening dominates the sky.";
       if (SelfPlayer.dayStart) {
           if (currentTime()) "The sun hangs on a hazy horizon, burnt red and setting.";
           "The sun hangs on a clear horizon, burnt red and setting.";
       }
       if (SelfPlayer.eveningTime) "The sun has dipped below the horizon though the last rays of light illuminate the sky in an orange hue.";
       if (SelfPlayer.preMorning) "The dark purple of morning fills the sky.";
       if (SelfPlayer.earlyEvening)"The sun set awhile ago - the sky a mixture of red and purple.";
       "It's dark. The sun long gone.";
 ];

 [ MLookUp;
       print "You look up, seeing a streak in the sky for a second. You suppose it's a ";
       if (tattooShopNick.askAboutTom) "meteor.";
       "ufo.";
 ];
