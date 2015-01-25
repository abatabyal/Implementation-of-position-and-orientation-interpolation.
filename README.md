# Implementation-of-position-and-orientation-interpolation.
The objectives for this project are as follows:
(1) Demonstration of familiarity with orientation interpolation using quaternions.
(2) Implementation of position interpolation.

A file called robot.key that contains the robot joint variable positions and velocities at
key frames. From this file you are to generate the file robot.ang used by animate that
contains the values of the joint variables for each frame. The format for robot.key is
defined as:
n1 n2
q1 q2 : : : qn
q˙1 q˙2 : : : q˙n
...
where n1 is an integer that denotes the number of key frames, n2 is an integer that
denotes the total number of frames to be in the simulation (n2=n1 may not necessarily be
an integer), and qi and q˙i denotes the position and velocity of joint i at a control point

A file called object.key that contains the homogeneous transformation describing an
object’s position and orientation at key frames. From this file you are to generate the
file object.traj that contains the homogeneous transformations for the object at every
frame. The format for the file object.key is:
n1 n2
nx ox ax px
ny oy ay py
nz oz az pz
...
where n1 and n2 have the same definition as above. The interpolation is to be done by
maintaining continuity in the velocity.
