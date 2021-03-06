^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package yocs_velocity_smoother
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.4.0 (2013-08-29)
------------------
* Add bugtracker and repo info URLs.
* Changelogs at package level.
* Separate and comment velocity feedback remaps.
* License link fixed.

0.3.0 (2013-07-02)
------------------
* Fix on velocity smoother to deal with low-rate simulated time (namely Stage).
* Allow using end velocity commands as robot feedback (until now we can use only odometry).

0.2.3 (2013-04-15)
------------------

0.2.2 (2013-02-10)
------------------

0.2.1 (2013-02-08)
------------------

0.2.0 (2013-02-07)
------------------
* Catkinized.

0.1.3 (2013-01-08)
------------------
* Dynamic reconfigure for velocity/acceleration limits.
* Fix on deceleration smoothing.

0.1.2 (2013-01-02)
------------------
* Add test program.
* Add licensing.

0.1.1 (2012-12-21)
------------------
* Keep direction constant when smoothing velocities, i.e. draw constant arcs. To do so we must sometimes over-limit dv or dw. 
* Bound velocity in addition to acceleration. Also set physically meaningful values for acceleration.

0.1.0 (2012-12-05)
------------------
* Initial version.
