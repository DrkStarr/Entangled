
! ---------------------------------------------------------------------------- !
!       BROKEN TUBE. 09/24/17
!

  Movabl  brokenTube "broken vacuum tube"
    with  name 'broken' 'vacuum' 'tube' 'black' 'glass' 'tubes',
          before [;
              Examine, Search:
                  "Looking over the row of tubes, you see one is black on the inside. It's damaged and will need replacing.";
              Open, Close:
                  "You don't need to do that.";
              Pull, Remove, Take:
                  if (basementTimeMachine.removeBrokenTube == false) {
                      basementTimeMachine.removeBrokenTube = true;
                      remove self;
                      basementTubes.&name-->0 = 'tubes';
                      "You pull out the broken tube throwing it to the ground. It shatters on contact.";
                  }
              Rub:
                  print "(first taking the broken vacuum tube)^";
                  <<Take self>>;
              Pet, Touch:
                  "You feel nothing unexpected. The glass is smooth, though it's black on the inside.";
              PushDir, Push, Turn:
                  "The tube is seated in place. You need to pull it out.";
              SwitchOn, SwitchOff:
                  "It doesn't work like that.";
              Replace:
                  if (vacuumTubeAmp in player) <<Insert vacuumTubeAmp basementTimeMachine>>;
                  if (vacuumTubeTV in player) <<Insert vacuumTubeTV basementTimeMachine>>;
                  "You don't have anything to replace it with.";
          ],
    has   container open;
