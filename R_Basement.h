! The spark plug is fused in place
! It has to be pulled out with a pair of pliers
! A dull crystal is in the machine
! ---------------------------------------------------------------------------- !
!       BASEMENT. 12/19/16
!
! if (basement.firstTime)
!
  Room    basement "Basement"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  bowlingAlleyBar.firstTime = false;
                  move backLotField to backLot;
                  if (backLotDumpster.bottleTaken) backLotDumpster.takenBeforeBasement = true;
                  if (SelfPlayer.kidsRunAway) SelfPlayer.kidsGone = true;
                  else {
                      SelfPlayer.kidsRunAway = true;
                      remove bowlingAlleyKids;
                  }
                  ! Save Time
                  iSaveHour = iHour;
                  iSaveMinute = iMinute;
                  iSaveAMPM = iAMPM;
                  if (iHour == 1 || iHour == 12) {
                      iHourHarryLeaves = 1;
                  } else {
                      if (iHour >= 2 && iHour <= 8 && iAMPM == 0) {
                          iHourHarryLeaves = 0;
                          remove theTavernHarry;
                          theTavernNick.harryLeftOnOwn = true;
                          theTavernObj.advanceNick = true;
                      } else {
                          iHourHarryLeaves = iHour + 1;
                      }
                  }
                  iRoom++;
              }
              SelfPlayer.outside = false;
              if (self.seenFirstTime) print "Lights dim and flicker. A fuse pops. ";
              print "A small explosion rocked this place with walls charred in the aftermath. ";
              if (basementGenerator.generatorOn) print "A cobbled-together machine sits in the center of this room. Lights on it flash with life. The generator next to it is turned on.";
              else print "What's left is a cobbled-together machine sitting in the center of this room. The generator next to it is shut down.";
              if (socketWrench in basementWorkbench) {} else {
                  print " In the corner is a bench.";
              }
              if (self.seenFirstTime) {
                  self.seenFirstTime = false;
                  print "^^Whoever did this is gone, though you can't help but wonder why the walls are charred.";
              }
              " Stairs lead out of the basement.";
          ],
          u_to [;
              <<Enter basementStairs>>;
          ],
          cant_go [;
              "The basement is small. No larger than the living room. You can go up the stairs.";
          ],
          before [;
              Exit:
                  <<Enter basementStairs>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "The house is quiet but has an electrical hum of its own.";
              Smell:
                  "The overpowering smell of burnt hair and cooked meat pervades the room.";
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          seenFirstTime true;

! 12/19/16

  RoomObj -> basementObj "room"
    with  name 'room' 'area' 'basement' 'house' 'home' 'place',
          description [;
                    <<Look basement>>;
          ],
          before [;
              Search:
                  "You look over the room. It seems to be covered in a thin layer of grease.
                  Something that sticks to you and doesn't want to come off.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 12/19/16

  Object  -> basementStairs "stairs"
    with  name 'stair' 'step' 'stairs' 'steps',
          before [;
              Enter, Go, Climb:
                  if (basementTimeMachine.seenMachine) {
                      PlayerTo(hallwayHouse);
                      rtrue;
                  }
                  "You should examine the room a little closer.";
              Examine, Search:
                  "The stairs go up.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the house.";
          ],
     has  concealed static pluralname;

! 12/19/16

  Object  -> basementTimeMachine "machine"
    with  name 'large' 'time' 'machine' 'temporal' 'ph00main' 'ph00panel' 'date' 'dates' 'ph00display' 'center' 'ph00501',
          before [;
              Examine:
                  self.seenMachine = true;
                  if (basementGenerator.generatorOn) {
                      print "There are similar dates in the center of the panel. One is set to October 1980. The other October 2020.";
                      if (FixedMachine()) {
                          "^^The button underneath the display panel is green.";
                      } else {
                          print " There's a button here too, but it's red because the machine isn't fixed.";
                      }
                  } else {
                      print "It's a strange piece of machinery with a metal arm that comes off one end.
                      But there's no power going to it, and the panel in the middle is blank.";
                  }
                  print "^^Looking it over further, you find ";
                  if (basementGenerator.generatorOn) {
                      print "that one of the vacuum tubes ";
                      if (self.insertVacuumTube) {
                          print "has been replaced";
                      } else {
                          if (self.removeBrokenTube) print "is gone";
                          else print "that ran the thing is black as night";
                      }
                      if (self.insertCrystalShard) {
                          print ", and the crystal lodged in the metal arm is clear and new";
                      } else {
                          if (self.removeBrokenCrystal) {
                              print ", and the housing at the end of the metal arm is missing a crystal";
                          } else {
                              print ", and the crystal lodged in the metal arm is cloudy and dull";
                          }
                      }
                      ".";
                  }
                  print "the lack of power comes from a generator that's off. One of the vacuum tubes ";
                  if (self.insertVacuumTube) {
                      print "has been replaced";
                  } else {
                      if (self.removeBrokenTube) print "is gone";
                      else print "that ran the thing is black as night";
                  }
                  if (self.insertCrystalShard) {
                      print ", and the crystal lodged in the metal arm is clear and new";
                  } else {
                      if (self.removeBrokenCrystal) {
                          print ", and the housing at the end of the metal arm is missing a crystal";
                      } else {
                          print ", and the crystal lodged in the metal arm is cloudy and dull";
                      }
                  }
                  if (FixedMachine()) ".";
                  if (basementTimeMachine.resetTimeMachine) ". Besides that, it should work.";
                  ". Besides that, it might work.";
              Fix:
                  if (FixedMachine()) {
                      if (basementGenerator.generatorOn) "The machine is fixed, you need to press the button.";
                      "The machine is fixed, you need to turn it on.";
                  }
                  if (vacuumTubeAmp in player) <<Insert vacuumTubeAmp basementTimeMachine>>;
                  if (vacuumTubeTV in player) <<Insert vacuumTubeTV basementTimeMachine>>;
                  if (crystalShard in player) <<Insert crystalShard basementTimeMachine>>;
                  if (crystalBall in player) {
                      print "(trying to put the crystal ball into the arm)^";
                      <<Insert crystalBall basementTimeMachine>>;
                  }
                  if (crystalCat in player) {
                      print "(trying to put the crystal cat into the arm)^";
                      <<Insert crystalCat basementTimeMachine>>;
                  }
                  "If only it were that simple.";
              Pet, Touch:
                  if (FixedMachine()) {
                      if (basementGenerator.generatorOn) "The machine feels warm to the touch.";
                  }
                  "The machine feels cold to the touch.";
              LookUnder:
                  if (basementTimeMachine.removeBrokenCrystal) "It's dark and hard to see underneath the machine, and there's no reason to retrieve the crystal.";
                  "It's dark and hard to see underneath the machine.";
              Set, SetTo:
                  if (basementGenerator.generatorOn) "There doesn't seem to be a way to change the dates.";
              SwitchOn:
                  if (basementGenerator.generatorOn) {
                      if (FixedMachine()) return EndGame();
                      "Turning on the machine does nothing, but the button is red.";
                  }
                  if (FixedGenerator()) {
                      basementGenerator.generatorOn = true;
                      move basementButton to basement;
                      if (FixedMachine()) basementButton.&name-->0 = 'green';
                      else basementButton.&name-->0 = 'red';
                      basementLights.&name-->0 = 'ph00500';
                      basementTimeMachine.&name-->10 = 'lights';
                      print "(first starting the generator)^You give the ripcord a good tug, and the generator springs to life.
                      The machine next to it lights up";
                      if (basementGenerator.genOnFirstTime) {
                          basementGenerator.genOnFirstTime = false;
                          print ". The panel displaying some dates";
                      }
                      print ".^^";
                      if (FixedMachine()) return EndGame();
                      "Turning on the machine does nothing, but the button is red.";
                  }
                  "Nothing happens. There's no power going to the machine.";
              SwitchOff:
                  if (basementGenerator.generatorOn) "You can't. The generator controls it.";
                  "Nothing happens. There's no power going to the machine.";
              Open, Close:
                  "You don't need to get inside the machine.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The machine doesn't need to go anywhere.";
          ],
          seenMachine false,
          removeBrokenTube false,
          insertVacuumTube false,
          removeBrokenCrystal false,
          insertCrystalShard false,
          resetTimeMachine false,
     has  concealed static switchable container open;

! 08/09/2020

  Object  -> basementTimePanel "panel"
    with  name 'panel' 'display' 'plate',
          before [;
              Examine:
                  if (basementGenerator.generatorOn) {
                      print "There are similar dates in the center of the panel. One is set to October 1980. The other October 2020.";
                      if (FixedMachine()) {
                          "^^The button underneath the display is green.";
                      } else {
                          " There's a button here too, but it's red because the machine isn't fixed.";
                      }
                  }
                  "Since the panel's not lit up, you don't see any buttons. There's no power going to the machine.";
              Pet, Push, SwitchOn:
                  if (basementGenerator.generatorOn) {
                      if (FixedMachine()) return EndGame();
                      "That does nothing, but the button is red.";
                  }
                  "The panel is blank, and the machine is off. It's not working.";
              Set, SetTo:
                  if (basementGenerator.generatorOn) "There doesn't seem to be a way to change the dates.";
              Fix:
                  <<Fix basementTimeMachine>>;
              SwitchOff:
                  if (basementGenerator.generatorOn) "You can't. The generator controls it.";
                  "Nothing happens. There's no power going to the machine.";
          ],
     has  concealed static;

  [ FixedMachine iTest;
        iTest = 0;
        if (basementTimeMachine.insertVacuumTube) iTest++;
        if (basementTimeMachine.insertCrystalShard) iTest++;
        if (iTest == 2) rtrue;
        rfalse;
  ];

  [ FixedGenerator;
        if (sparkPlugCar in basementGenerator) rtrue;
        if (sparkPlugMower in basementGenerator) rtrue;
        rfalse;
  ];

! 4/23/19

  Object  -> basementMetalArm "metal arm"
    with  name 'housing' 'metal' 'arm',
          before [;
              Examine:
                  if (basementTimeMachine.removeBrokenCrystal == false)
                      "The metal arm comes off the machine holding a crystal that's cloudy and dull in its housing.";
                  if (basementTimeMachine.insertCrystalShard)
                      "The metal arm comes off the machine holding a crystal shard in its housing.";
                  "The metal arm comes off the machine and has an empty housing.";
              Turn, PushDir, Push, Pull:
                  "You don't want to do that. You'd only mess with the alignment of the crystal.";
              Take, Remove:
                  "You can't do that. It's part of the machine.";
          ],
     has  concealed static container open;

! 5/26/17

  Object  -> basementWalls "walls"
    with  name 'wall' 'walls' 'residue',
          before [;
              Examine, Search:
                  "The walls are burnt orange and charred with a residue.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The walls don't need to go anywhere.";
              Rub:
                  self.tryToClean = true;
                  "Trying to clean one of the walls, you fail to get anywhere. Your hands now covered in sticky grease.";
              Touch:
                  if (self.tryToClean) "Your hands are sticky and would only add to the residue.";
                  "You test one of the walls to see what it's covered in. Rubbing your fingers together, it feels like a layer of grease.";
              SmellNoun:
                  "You put your nose up to the wall and sniff. It's just as disgusting as the rest of the room, only a little stronger.";
          ],
          tryToClean false,
     has  concealed static pluralname;

! 12/19/16

  Object  -> basementGenerator "generator"
    with  name 'generator' 'gen' 'opening' 'middle' 'side' 'scorched',
          before [;
              Examine:
                  if (self.generatorOn) "The device is already running, providing power to the machine in the center of the room.";
                  print "There's a ripcord on the side of the scorched generator, ";
                  if (self.insertSparkPlug) "and it has a fresh spark plug in it.";
                  if (self.removeFusedPlug) "and the opening for the spark plug is empty.";
                  if (self.firstLook) {
                      self.firstLook = false;
                      "and a fused plug sits where a good one should be.";
                  }
                  "and the fused plug inside is useless.";
              Fix:
                  if (self.insertSparkPlug) "It looks like it's already fixed.";
                  if (sparkPlugCar in player) <<Insert sparkPlugCar basementGenerator>>;
                  if (sparkPlugMower in player) <<Insert sparkPlugMower basementGenerator>>;
                  "If only it were that simple.";
              SwitchOff:
                  if (self.generatorOn) {
                      self.generatorOn = false;
                      if (basementButton in basement) remove basementButton;
                      basementLights.&name-->0 = 'lights';
                      basementTimeMachine.&name-->10 = 'ph00501';
                      if (FixedMachine()) "You shut it off even though the machine is fixed.";
                      "You shut it off. Might as well save on the fuel.";
                  }
                  "That's already off.";
              SwitchOn:
                  if (self.insertSparkPlug) {
                      if (self.generatorOn) "The generator is already running.";
                      self.generatorOn = true;
                      move basementButton to basement;
                      if (FixedMachine()) basementButton.&name-->0 = 'green';
                      else basementButton.&name-->0 = 'red';
                      basementLights.&name-->0 = 'ph00500';
                      basementTimeMachine.&name-->10 = 'lights';
                      print "You give the ripcord a good tug, and the generator springs to life.
                      The machine next to it lights up";
                      if (self.genOnFirstTime) {
                          self.genOnFirstTime = false;
                          print ". The panel displaying some dates";
                      }
                      ".";
                  }
                  print "You give the ripcord a good tug, but the engine fails to kick over";
                  if (self.removeFusedPlug) " without a spark plug in it.";
                  if (self.turnOnFail) {
                      self.turnOnFail = false;
                      ". Looking at it a little closer, you see the spark plug is fused. It'll need replacing.";
                  }
                  ".";
              Open, Close:
                  "You don't need to do that.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The generator doesn't need to go anywhere.";
              Rub:
                  "You push around some grease, but it does little to clean it.";
              Pet, Touch:
                  "You touch the generator, but your hand comes away sticky.";
          ],
          firstLook true,
          turnOnFail true,
          genOnFirstTime true,
          removeFusedPlug false,
          insertSparkPlug false,
          generatorOn false,
      has concealed static switchable container open;

! 6/3/17

  Object  -> basementRipcord "ripcord"
    with  name 'ripcord' 'cord',
          before [;
              Examine, Search:
                  <<Examine basementGenerator>>;
              Fix:
                  <<Fix basementGenerator>>;
              SwitchOff:
                  print "(shutting off the generator)^";
                  <<SwitchOff basementGenerator>>;
              Pull, SwitchOn:
                  <<SwitchOn basementGenerator>>;
              Take, Remove, Turn, PushDir, Push:
                  "You can't do that. It's part of the generator.";
              Pet:
                  "You feel nothing unexpected.";
          ],
      has concealed static;

! 06/04/17

  OutRch  -> basementLights "lights"
    with  name 'lights' 'light' 'overheads' 'overhead',
          before [;
              Examine:
                  "The lights flicker a bit, but stay on even though you heard one of the fuses pop.";
          ],
     has  pluralname;

! 08/11/20

  Object  -> basementTubes "tubes"
    with  name 'ph00404',
          before [;
              Examine:
                  "Looking over the vacuum tubes, you see one of them is missing.";
              Fix:
                  if (vacuumTubeAmp in player) <<Insert vacuumTubeAmp basementTimeMachine>>;
                  if (vacuumTubeTV in player) <<Insert vacuumTubeTV basementTimeMachine>>;
                  "If only it were that simple.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The tubes inside the machine look fine, except for the missing one. You'll need to find a replacement.";
              Open, Close:
                  "You don't need to do that.";
              Rub, Pet, Touch:
                  "You shouldn't touch the tubes. Any grease on your hands would damage them.";
          ],
     has  concealed static pluralname container open;

! 5/7/18

  Object  -> basementWorkbench "workbench"
    with  name 'bench' 'workbench' 'counter',
          describe [;
              if (socketWrench in self) "^There's a workbench tucked in the corner with a socket wrench on it.";
              rtrue;
          ],
          before [;
              Examine, Search:
                  print "A small workbench sits in the corner. Whatever instruments were on it were destroyed in the blast";
                  if (socketWrench in self) ". The only tool that survived the shock is a socket wrench that looks pitted.";
                  ", except for the wrench.";
              LookUnder:
                  "There's nothing underneath the workbench - not even cobwebs since the blast hit the room.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The bench doesn't need to go anywhere.";
              Pet:
                  "You feel nothing unexpected.";
          ],
      has static supporter;

! 1/16/18

  Object  basementButton "button"
    with  name 'red' 'button',
          before [;
              Climb:
                  "You're supposed to push it.";
              Examine, Search:
                  if (FixedMachine()) "Lit up green, it's an indication the machine is fixed.";
                  "Lit up red, it's an indication the machine isn't fixed.";
              SwitchOff:
                  print "(shutting off the generator)^";
                  <<SwitchOff basementGenerator>>;
              Pet, Push, SwitchOn:
                  if (FixedMachine()) return EndGame();
                  "That does nothing, but the button is red.";
                    Take, Remove, Turn, PushDir, Push:
                  "You can't do that. It's part of the machine.";
          ],
          pushed false,
      has concealed static;
