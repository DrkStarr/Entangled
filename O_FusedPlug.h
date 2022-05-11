
! ---------------------------------------------------------------------------- !
!       FUSED PLUG. 05/31/17
!
  Movabl  fusedPlug "fused spark plug"
    with  name 'fused' 'plug' 'spark' 'fuse',
          before [;
              Examine, Search:
                  "The blast that shook this room somehow fused the spark plug at the core.
                  Now it's a useless hunk of metal screwed into the generator.";
              Pull, Remove, Take, Turn:
                  if (socketWrench in player) {
                      basementGenerator.removeFusedPlug = true;
                      remove self;
                      "Using the socket wrench, you unscrew the spark plug. But when you pull it
                      out of the cylinder, it crumbles to dust in your hand.";
                  }
                  "Without a wrench, you're not going to be able to remove it.";
              Pet:
                  "You feel nothing unexpected.";
              Rub, Touch, Pet:
                  print "(first taking the fused plug)^";
                  <<Take self>>;
              PushDir, Push:
                  "That's not going to help. This spark plug is fused at the core and is useless.";
              SwitchOn, SwitchOff:
                  "It doesn't work like that.";
              Replace:
                  if (sparkPlugCar in player) <<Insert sparkPlugCar basementGenerator>>;
                  if (sparkPlugMower in player) <<Insert sparkPlugMower basementGenerator>>;
                  "You don't have anything to replace it with.";
          ];
