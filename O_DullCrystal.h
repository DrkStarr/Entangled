
! ---------------------------------------------------------------------------- !
!       DULL CRYSTAL. 01/16/18
!
  Movabl  dullCrystal "dull crystal"
    with  name 'dull' 'crystal' 'quartz' 'dark' 'cloudy',
          before [;
              Examine, Search:
                  "The crystal is dark and cloudy. A lot of electricity must have been going through it.
                  It looks like quartz, so it should be clear.";
              Pull, Remove, Take:
                  basementTimeMachine.removeBrokenCrystal = true;
                  remove self;
                  "You pull out the dull crystal from the metal arm, tossing it aside. It rolls out of sight under the large machine.";
              Rub, Touch, Pet:
                  print "(first taking the dull crystal)^";
                  <<Take self>>;
              PushDir, Push, Turn:
                  "The crystal is seated in place. You need to pull it out.";
              SwitchOn, SwitchOff:
                  "It doesn't work like that.";
              Replace:
                  if (crystalBall in player) "Since it's clear quartz, it might work, but it's too big to fit in there.";
                  if (crystalCat in player) "Since it's clear quartz, it might work, but it's too big to fit in there.";
                  if (crystalShard in player) <<Insert crystalShard basementTimeMachine>>;
                  "You don't have anything to replace it with.";
          ];
