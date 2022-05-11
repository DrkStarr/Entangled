! The statue points at a large tree.
! Inside a knott in the tree the player could find something needed in the game.
! ---------------------------------------------------------------------------- !
!       PARK. 6/1/17
!
  Room    smallPark
   with   short_name [;
              if (smallParkBench.playerSit == false) {
                  print "Park";
                  rtrue;
              }
              print "Park ";
              style roman;
              print "(on the bench)";
              rtrue;
          ],
          description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              if (self.firstTimeDaemon) {
                  self.firstTimeDaemon = false;
                  StartDaemon(smallParkEddie);
              }
              SelfPlayer.outside = true;
              if (basement.firstTime) {
                  "There's a statue in the center of the park, surrounded by benches in a wide radius.
                  It's marked up with spray paint. Shrubs and trees line the park
                  creating the green wall that keeps the city out. Closed in, you can head
                  back across the street north to the town hall.";
              }
              print "There's a statue of an elder statesman in the center of the park, surrounded by
              benches in a wide radius. Shrubs and trees line the park creating the green wall
              that keeps the city out. Closed in, you can head back across the street north to
              the town hall.^";
              if (smallParkEddie in self) {
                  if (dollarBill in self) {
                      move dollarBill to player;
                      self.seenEddie = true;
                      dollarBill.dollarScore = true;
                      "^~Oh. I guess this is yours,~ a rough-looking guy says, picking up the dollar bill and handing it to you.";
                  } else {
                      self.seenEddie = true;
                      "^A rough-looking guy in shabby clothes sits on one of the benches.";
                  }
              }
              if (babushka in self) {
                  if (dollarBill in self) {
                      if (self.seenEddie) "^The man's gone leaving behind a scarf. A dollar bill flutters in the wind.";
                      else  "^A scarf has been left behind in the park. A dollar bill flutters in the wind.";
                  } else {
                      if (self.seenEddie) "^The man's gone leaving behind a scarf.";
                      else  "^A scarf has been left behind in the park.";
                  }
              }
              if (dollarBill in self) {
                  "^A dollar bill flutters in the wind.";
              }
              rtrue;
          ],
          n_to [;
              <<Enter smallParkTownHall>>;
          ],
          u_to [;
              if (smallParkBench.playerSit) <<GetOff smallParkBench>>;
          ],
          cant_go [;
              "You can head north back to the town hall.";
          ],
          before [;
              Exit:
                  if (smallParkBench.playerSit) <<GetOff smallParkBench>>;
                  <<Enter smallParkTownHall>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  print "A peaceful drone comes from the city around you";
                  if (rustyGate.dogBarking) ", but it's broken by a dog barking in the distance.";
                  ". Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sorry:
                  if (smallParkEddie in smallPark) <<Answer t_sorry smallParkEddie>>;
              Wave:

              Yes:
                  if (smallParkEddie in smallPark) <<Answer t_yes smallParkEddie>>;
              No:
                  if (smallParkEddie in smallPark) <<Answer t_no smallParkEddie>>;
              Sleep:
                  return roomSleep();
          ],
          firstLook true,
          firstTimeDaemon false,
          seenEddie false,
          firstTime true;

! 6/1/17

  RoomObj -> smallParkObj "park"
    with  name 'area' 'park' 'place',
          description [;
              <<Look smallPark>>;
          ],
          before [;
              Search:
                  "You look around the area finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 6/1/17

  OutRch  -> smallParkTownHall "town hall"
    with  name 'town' 'hall',
          before [;
              Enter, Go:
                  if (smallParkBench.playerSit) {
                      smallParkBench.playerSit = false;
                      print "(first getting up off the bench)^";
                  }
                  print "You cross the street, stopping at the town hall.^";
                  PlayerTo(outsideTownHall);
                  rtrue;
              Examine:
                  if (basement.firstTime)
                      "The town hall is across the street from the park - the building is tagged with graffiti.
                      The kids have been restless lately.";
                  "The town hall is across the street from the park - the building was once covered in graffiti.
                  Cleaned up, people must take care of the area.";
          ];

! 01/24/18

  Object  -> smallParkBench "benches"
    with  name 'bench' 'benches',
          before [;
              Enter:
                  if (self.playerSit) "You are already sitting down.";
                  self.playerSit = true;
                  if (smallParkEddie in smallPark) "You sit down on the bench away from the bum.";
                  "You sit down, taking a load off for a minute.";
              Examine, Search:
                  if (smallParkEddie in smallPark)
                      "Benches line the park surrounding the statue in the middle.
                      On one of them, an older man waits for a handout.";
                  if (babushka in smallPark)
                      "Benches line the park surrounding the statue in the middle.
                      On one of them, a scarf has been left behind.";
                  "Benches line the park surrounding the statue in the middle.";
              GetOff:
                  if (self.playerSit) {
                      self.playerSit = false;
                      "Standing up, you get off the bench.";
                  }
              LookUnder:
                  if (self.playerSit) "Looking between your legs, dried bird droppings are the only thing you find.";
                  "Dried bird droppings are the only thing you find.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The benches don't need to go anywhere.";
          ],
          playerSit false,
    has   pluralname concealed static;

! 03/14/19

  Object  -> smallParkDroppings "droppings"
    with  name 'dried' 'bird' 'droppings' 'dropping',
          before [;
              Examine:
                  if (basement.firstTime)
                      "Bird droppings line the park underneath the benches.";
                  "Bird droppings cover the statue and line the park underneath the benches.";
              Take, Remove, Turn, PushDir, Push, Pull, Rub, Touch, Search, Pet:
                  "It's excrement. You don't need to touch that.";
          ],
    has   pluralname concealed static;

! 01/25/18

  OutRch  -> smallParkStatue "statue"
    with  name 'statue' 'elder' 'statesman',
          before [;
              Climb:
                  "You think about climbing the pedestal and pulling yourself up, but the effort would do little.";
              Enter, Go:
                  "You are already here.";
              Examine:
                  if (basement.firstTime)
                      "The statue is of a statesman, something leftover from another time.
                      All the kids seem to hate him. He's been painted on, tagged, and then
                      painted over. He stands on a pedestal, and the layers of disrespect are
                      almost comical.";
                  "The statue is of a statesman, something leftover from another time.
                  He stands on a pedestal. Rumor has it he founded this city. Covered
                  in droppings, no one respects him.";
              LookUnder:
                  "It's made from solid brass. You can't pick it up.";
              Read:
                  <<Read smallParkPedestal>>;
              Rub:
                  if (basement.firstTime) "Not with a bucket of thinner, and a scrub brush from hell, are you going to get that clean.";
                  "Not with a scrub brush from hell are you going to get that clean.";
              Push, PushDir, Pull:
                  "The statue is made of solid bronze. It's not going to topple over that easily.";
              Take, Remove, Turn:
                  "The statue doesn't need to go anywhere.";
          ];

! 01/25/18

  Object  -> smallParkPedestal "pedestal"
    with  name 'pedestal' 'plaque' 'name' 'pillar',
          before [;
              Climb:
                  "You think about climbing the pedestal, but the effort would do little.";
              Enter, Go:
                  "You are already here.";
              Examine, Search:
                  if (basement.firstTime)
                      "The pedestal has been tagged too and then spray painted over.
                      Underneath it all, you can see a name carved into it.";
                  "The pedestal underneath the statue has a name carved into it.";
              LookUnder:
                  "It's made from solid brass. You can't pick it up.";
              Read:
                  print "Pitted from a lifetime of weather, the name upon the pedestal is hard to read
                  and makes no sense. It says, Yukypah Heef";
                  if (self.seenFirstTime) {
                      self.seenFirstTime = false;
                      ".^^You doubt it has any real meaning.";
                  }
                  ".";
              Rub:
                  <<Rub smallParkStatue>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The pedestal doesn't need to go anywhere.";
          ],
          playerSit false,
          seenFirstTime true,
    has   concealed static;

! 05/20/18

  Object  -> smallParkTrees "trees"
    with  name 'tree' 'trees' 'shrub' 'shrubs' 'grass' 'grassy' 'wall' 'green',
          before [;
              Climb:
                  "That's no way to exit the park. Try going north.";
              Examine:
                  "Surrounded by trees and shrubs that wall in the whole thing, the park has a calm feeling.";
              Enter, Go, Search:
                  "Trees and shrubs make up a wall that you can't pass through.";
              Take, Turn, Remove:
                  "The trees aren't going anywhere.";
              PushDir, Push, Pull:
                  "Push on them as you might, the trees aren't going anywhere.";
          ],
     has  concealed static pluralname;

! 10/09/19

  ORchGr  -> smallParkTags "tags"
    with  name  'tag' 'tags' 'names',
          before [;
              Go, Enter:
                  "You are already here.";
              Examine, Read:
                  "The tags have been painted on top of each other. It looks like all the kids in the area are trying to take credit.";
          ],
    has   pluralname;

! 08/07/20

  ORchGr  -> smallParkGraffiti "graffiti"
    with  name  'graffiti' 'paint' 'painting',
          before [;
              Go, Enter:
                  "You are already here.";
              Examine, Read:
                  "The graffiti is random for the most part, but the statue's eyes are colored in with a smile painted underneath.";
          ];
