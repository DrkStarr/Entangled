
! ---------------------------------------------------------------------------- !
!       BROKEN TUBE. 01/01/18
!
  Movabl  brokenTubeYard "broken vacuum tubes"
    with  name 'broken' 'vacuum' 'tube' 'tubes' 'glass',
          before [;
              Examine, Search:
                  "Broken vacuum tubes line the back of the television - jagged and sharp.";
              Pet, Pull, Remove, Take, Rub, PushDir, Push, Turn, Touch:
                  "You'd only cut your hands on the glass.";
              SwitchOn, SwitchOff:
                  "It doesn't work like that.";
          ],
    has   pluralname;
