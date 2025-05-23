namespace uipc::backend::cuda::distance::details
{
template <typename T>
MUDA_GENERIC void g_EE(
    T v01, T v02, T v03, T v11, T v12, T v13, T v21, T v22, T v23, T v31, T v32, T v33, T g[12])
{
    T t11;
    T t12;
    T t13;
    T t14;
    T t15;
    T t16;
    T t17;
    T t18;
    T t19;
    T t32;
    T t33;
    T t34;
    T t35;
    T t36;
    T t37;
    T t44;
    T t45;
    T t46;
    T t75;
    T t77;
    T t76;
    T t78;
    T t79;
    T t80;
    T t81;
    T t83;

    /* G_EE */
    /*     G = G_EE(V01,V02,V03,V11,V12,V13,V21,V22,V23,V31,V32,V33) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.3. */
    /*     14-Jun-2019 13:58:25 */
    t11   = -v11 + v01;
    t12   = -v12 + v02;
    t13   = -v13 + v03;
    t14   = -v21 + v01;
    t15   = -v22 + v02;
    t16   = -v23 + v03;
    t17   = -v31 + v21;
    t18   = -v32 + v22;
    t19   = -v33 + v23;
    t32   = t14 * t18;
    t33   = t15 * t17;
    t34   = t14 * t19;
    t35   = t16 * t17;
    t36   = t15 * t19;
    t37   = t16 * t18;
    t44   = t11 * t18 + -(t12 * t17);
    t45   = t11 * t19 + -(t13 * t17);
    t46   = t12 * t19 + -(t13 * t18);
    t75   = 1.0 / ((t44 * t44 + t45 * t45) + t46 * t46);
    t77   = (t16 * t44 + t14 * t46) + -(t15 * t45);
    t76   = t75 * t75;
    t78   = t77 * t77;
    t79   = (t12 * t44 * 2.0 + t13 * t45 * 2.0) * t76 * t78;
    t80   = (t11 * t45 * 2.0 + t12 * t46 * 2.0) * t76 * t78;
    t81   = (t18 * t44 * 2.0 + t19 * t45 * 2.0) * t76 * t78;
    t18   = (t17 * t45 * 2.0 + t18 * t46 * 2.0) * t76 * t78;
    t83   = (t11 * t44 * 2.0 + -(t13 * t46 * 2.0)) * t76 * t78;
    t19   = (t17 * t44 * 2.0 + -(t19 * t46 * 2.0)) * t76 * t78;
    t76   = t75 * t77;
    g[0]  = -t81 + t76 * ((-t36 + t37) + t46) * 2.0;
    g[1]  = t19 - t76 * ((-t34 + t35) + t45) * 2.0;
    g[2]  = t18 + t76 * ((-t32 + t33) + t44) * 2.0;
    g[3]  = t81 + t76 * (t36 - t37) * 2.0;
    g[4]  = -t19 - t76 * (t34 - t35) * 2.0;
    g[5]  = -t18 + t76 * (t32 - t33) * 2.0;
    t17   = t12 * t16 + -(t13 * t15);
    g[6]  = t79 - t76 * (t17 + t46) * 2.0;
    t18   = t11 * t16 + -(t13 * t14);
    g[7]  = -t83 + t76 * (t18 + t45) * 2.0;
    t19   = t11 * t15 + -(t12 * t14);
    g[8]  = -t80 - t76 * (t19 + t44) * 2.0;
    g[9]  = -t79 + t76 * t17 * 2.0;
    g[10] = t83 - t76 * t18 * 2.0;
    g[11] = t80 + t76 * t19 * 2.0;
}

template <typename T>
MUDA_GENERIC void H_EE(
    T v01, T v02, T v03, T v11, T v12, T v13, T v21, T v22, T v23, T v31, T v32, T v33, T H[144])
{
    T t11;
    T t12;
    T t13;
    T t14;
    T t15;
    T t16;
    T t26;
    T t27;
    T t28;
    T t47;
    T t48;
    T t49;
    T t50;
    T t51;
    T t52;
    T t53;
    T t54;
    T t55;
    T t56;
    T t57;
    T t58;
    T t59;
    T t65;
    T t73;
    T t35;
    T t36;
    T t37;
    T t38;
    T t39;
    T t40;
    T t98;
    T t99;
    T t100;
    T t101;
    T t103;
    T t105;
    T t107;
    T t108;
    T t109;
    T t137;
    T t138;
    T t139;
    T t140;
    T t141;
    T t142;
    T t143;
    T t144;
    T t145;
    T t146;
    T t147;
    T t148;
    T t156;
    T t159;
    T t157;
    T t262;
    T t263;
    T t264;
    T t265;
    T t266;
    T t267;
    T t268;
    T t269;
    T t270;
    T t271;
    T t272;
    T t273;
    T t274;
    T t275;
    T t276;
    T t277;
    T t278;
    T t279;
    T t298;
    T t299;
    T t300;
    T t301;
    T t302;
    T t303;
    T t310;
    T t311;
    T t312;
    T t313;
    T t314;
    T t315;
    T t322;
    T t323;
    T t325;
    T t326;
    T t327;
    T t328;
    T t329;
    T t330;
    T t335;
    T t337;
    T t339;
    T t340;
    T t341;
    T t342;
    T t343;
    T t345;
    T t348;
    T t353;
    T t356;
    T t358;
    T t359;
    T t360;
    T t362;
    T t367;
    T t368;
    T t369;
    T t371;
    T t374;
    T t377;
    T t382;
    T t386;
    T t387;
    T t398;
    T t399;
    T t403;
    T t408;
    T t423;
    T t424;
    T t427;
    T t428;
    T t431;
    T t432;
    T t433;
    T t434;
    T t437;
    T t438;
    T t441;
    T t442;
    T t446;
    T t451;
    T t455;
    T t456;
    T t467;
    T t468;
    T t472;
    T t477;
    T t491;
    T t492;
    T t495;
    T t497;
    T t499;
    T t500;
    T t503;
    T t504;
    T t506;
    T t508;
    T t550;
    T t568;
    T t519_tmp;
    T b_t519_tmp;
    T t519;
    T t520_tmp;
    T b_t520_tmp;
    T t520;
    T t521_tmp;
    T b_t521_tmp;
    T t521;
    T t522_tmp;
    T b_t522_tmp;
    T t522;
    T t523_tmp;
    T b_t523_tmp;
    T t523;
    T t524_tmp;
    T b_t524_tmp;
    T t524;
    T t525;
    T t526;
    T t527;
    T t528;
    T t529;
    T t530;
    T t531;
    T t532;
    T t533;
    T t534;
    T t535;
    T t536;
    T t537;
    T t538;
    T t539;
    T t540;
    T t542;
    T t543;
    T t544;

    /* H_EE */
    /*     H = H_EE(V01,V02,V03,V11,V12,V13,V21,V22,V23,V31,V32,V33) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.3. */
    /*     14-Jun-2019 13:58:38 */
    t11  = -v11 + v01;
    t12  = -v12 + v02;
    t13  = -v13 + v03;
    t14  = -v21 + v01;
    t15  = -v22 + v02;
    t16  = -v23 + v03;
    t26  = -v31 + v21;
    t27  = -v32 + v22;
    t28  = -v33 + v23;
    t47  = t11 * t27;
    t48  = t12 * t26;
    t49  = t11 * t28;
    t50  = t13 * t26;
    t51  = t12 * t28;
    t52  = t13 * t27;
    t53  = t14 * t27;
    t54  = t15 * t26;
    t55  = t14 * t28;
    t56  = t16 * t26;
    t57  = t15 * t28;
    t58  = t16 * t27;
    t59  = t11 * t26 * 2.0;
    t65  = t12 * t27 * 2.0;
    t73  = t13 * t28 * 2.0;
    t35  = t11 * t11 * 2.0;
    t36  = t12 * t12 * 2.0;
    t37  = t13 * t13 * 2.0;
    t38  = t26 * t26 * 2.0;
    t39  = t27 * t27 * 2.0;
    t40  = t28 * t28 * 2.0;
    t98  = t11 * t15 + -(t12 * t14);
    t99  = t11 * t16 + -(t13 * t14);
    t100 = t12 * t16 + -(t13 * t15);
    t101 = t47 + -t48;
    t103 = t49 + -t50;
    t105 = t51 + -t52;
    t107 = t53 + -t54;
    t108 = t55 + -t56;
    t109 = t57 + -t58;
    t137 = t98 + t101;
    t138 = t99 + t103;
    t139 = t100 + t105;
    t140 = (t54 + -t53) + t101;
    t141 = (t56 + -t55) + t103;
    t142 = (t58 + -t57) + t105;
    t143 = t12 * t101 * 2.0 + t13 * t103 * 2.0;
    t144 = t11 * t103 * 2.0 + t12 * t105 * 2.0;
    t145 = t27 * t101 * 2.0 + t28 * t103 * 2.0;
    t146 = t26 * t103 * 2.0 + t27 * t105 * 2.0;
    t147 = t11 * t101 * 2.0 + -(t13 * t105 * 2.0);
    t148 = t26 * t101 * 2.0 + -(t28 * t105 * 2.0);
    t156 = 1.0 / ((t101 * t101 + t103 * t103) + t105 * t105);
    t159 = (t16 * t101 + t14 * t105) + -(t15 * t103);
    t157 = t156 * t156;
    t57  = pow(t156, 3.0);
    t58  = t159 * t159;
    t262 = t11 * t156 * t159 * 2.0;
    t263 = t12 * t156 * t159 * 2.0;
    t264 = t13 * t156 * t159 * 2.0;
    t265 = t14 * t156 * t159 * 2.0;
    t266 = t15 * t156 * t159 * 2.0;
    t267 = t16 * t156 * t159 * 2.0;
    t268 = (-v31 + v01) * t156 * t159 * 2.0;
    t269 = (-v21 + v11) * t156 * t159 * 2.0;
    t270 = (-v32 + v02) * t156 * t159 * 2.0;
    t271 = (-v22 + v12) * t156 * t159 * 2.0;
    t272 = (-v33 + v03) * t156 * t159 * 2.0;
    t273 = (-v23 + v13) * t156 * t159 * 2.0;
    t274 = (-v31 + v11) * t156 * t159 * 2.0;
    t275 = (-v32 + v12) * t156 * t159 * 2.0;
    t276 = (-v33 + v13) * t156 * t159 * 2.0;
    t277 = t26 * t156 * t159 * 2.0;
    t278 = t27 * t156 * t159 * 2.0;
    t279 = t28 * t156 * t159 * 2.0;
    t298 = t11 * t12 * t157 * t58 * 2.0;
    t299 = t11 * t13 * t157 * t58 * 2.0;
    t300 = t12 * t13 * t157 * t58 * 2.0;
    t301 = t26 * t27 * t157 * t58 * 2.0;
    t302 = t26 * t28 * t157 * t58 * 2.0;
    t303 = t27 * t28 * t157 * t58 * 2.0;
    t310 = (t35 + t36) * t157 * t58;
    t311 = (t35 + t37) * t157 * t58;
    t312 = (t36 + t37) * t157 * t58;
    t313 = (t38 + t39) * t157 * t58;
    t314 = (t38 + t40) * t157 * t58;
    t315 = (t39 + t40) * t157 * t58;
    t322 = (t59 + t65) * t157 * t58;
    t323 = (t59 + t73) * t157 * t58;
    t59  = (t65 + t73) * t157 * t58;
    t325 = (t47 * 2.0 + -(t48 * 4.0)) * t157 * t58;
    t53  = -t157 * t58;
    t56  = t48 * 2.0 - t47 * 4.0;
    t326 = t53 * t56;
    t327 = (t49 * 2.0 + -(t50 * 4.0)) * t157 * t58;
    t55  = t50 * 2.0 - t49 * 4.0;
    t328 = t53 * t55;
    t329 = (t51 * 2.0 + -(t52 * 4.0)) * t157 * t58;
    t54  = t52 * 2.0 - t51 * 4.0;
    t330 = t53 * t54;
    t53  = t157 * t58;
    t335 = t53 * t56;
    t337 = t53 * t55;
    t339 = t53 * t54;
    t340 = t143 * t143 * t57 * t58 * 2.0;
    t341 = t144 * t144 * t57 * t58 * 2.0;
    t342 = t145 * t145 * t57 * t58 * 2.0;
    t343 = t146 * t146 * t57 * t58 * 2.0;
    t345 = t147 * t147 * t57 * t58 * 2.0;
    t348 = t148 * t148 * t57 * t58 * 2.0;
    t36  = t98 * t143 * t157 * t159 * 2.0;
    t353 = t99 * t143 * t157 * t159 * 2.0;
    t356 = t99 * t144 * t157 * t159 * 2.0;
    t65  = t100 * t144 * t157 * t159 * 2.0;
    t358 = t107 * t143 * t157 * t159 * 2.0;
    t359 = t98 * t145 * t157 * t159 * 2.0;
    t360 = t108 * t143 * t157 * t159 * 2.0;
    t54  = t107 * t144 * t157 * t159 * 2.0;
    t362 = t99 * t145 * t157 * t159 * 2.0;
    t53  = t98 * t146 * t157 * t159 * 2.0;
    t56  = t109 * t143 * t157 * t159 * 2.0;
    t27  = t108 * t144 * t157 * t159 * 2.0;
    t55  = t100 * t145 * t157 * t159 * 2.0;
    t367 = t99 * t146 * t157 * t159 * 2.0;
    t368 = t109 * t144 * t157 * t159 * 2.0;
    t369 = t100 * t146 * t157 * t159 * 2.0;
    t38  = t107 * t145 * t157 * t159 * 2.0;
    t371 = t108 * t145 * t157 * t159 * 2.0;
    t374 = t108 * t146 * t157 * t159 * 2.0;
    t28  = t109 * t146 * t157 * t159 * 2.0;
    t377 = t98 * t147 * t157 * t159 * 2.0;
    t382 = t100 * t147 * t157 * t159 * 2.0;
    t386 = t107 * t147 * t157 * t159 * 2.0;
    t387 = t98 * t148 * t157 * t159 * 2.0;
    t103 = t108 * t147 * t157 * t159 * 2.0;
    t101 = t99 * t148 * t157 * t159 * 2.0;
    t398 = t109 * t147 * t157 * t159 * 2.0;
    t399 = t100 * t148 * t157 * t159 * 2.0;
    t403 = t107 * t148 * t157 * t159 * 2.0;
    t408 = t109 * t148 * t157 * t159 * 2.0;
    t73  = t137 * t143 * t157 * t159 * 2.0;
    t423 = t138 * t143 * t157 * t159 * 2.0;
    t424 = t138 * t144 * t157 * t159 * 2.0;
    t37  = t139 * t144 * t157 * t159 * 2.0;
    t427 = t140 * t143 * t157 * t159 * 2.0;
    t428 = t137 * t145 * t157 * t159 * 2.0;
    t16  = t140 * t144 * t157 * t159 * 2.0;
    t11  = t137 * t146 * t157 * t159 * 2.0;
    t431 = t141 * t143 * t157 * t159 * 2.0;
    t432 = t138 * t145 * t157 * t159 * 2.0;
    t433 = t141 * t144 * t157 * t159 * 2.0;
    t434 = t138 * t146 * t157 * t159 * 2.0;
    t105 = t142 * t143 * t157 * t159 * 2.0;
    t14  = t139 * t145 * t157 * t159 * 2.0;
    t437 = t142 * t144 * t157 * t159 * 2.0;
    t438 = t139 * t146 * t157 * t159 * 2.0;
    t35  = t140 * t145 * t157 * t159 * 2.0;
    t441 = t141 * t145 * t157 * t159 * 2.0;
    t442 = t141 * t146 * t157 * t159 * 2.0;
    t39  = t142 * t146 * t157 * t159 * 2.0;
    t446 = t137 * t147 * t157 * t159 * 2.0;
    t451 = t139 * t147 * t157 * t159 * 2.0;
    t455 = t140 * t147 * t157 * t159 * 2.0;
    t456 = t137 * t148 * t157 * t159 * 2.0;
    t13  = t141 * t147 * t157 * t159 * 2.0;
    t26  = t138 * t148 * t157 * t159 * 2.0;
    t467 = t142 * t147 * t157 * t159 * 2.0;
    t468 = t139 * t148 * t157 * t159 * 2.0;
    t472 = t140 * t148 * t157 * t159 * 2.0;
    t477 = t142 * t148 * t157 * t159 * 2.0;
    t47  = t143 * t144 * t57 * t58 * 2.0;
    t15  = t143 * t145 * t57 * t58 * 2.0;
    t491 = t143 * t146 * t57 * t58 * 2.0;
    t492 = t144 * t145 * t57 * t58 * 2.0;
    t12  = t144 * t146 * t57 * t58 * 2.0;
    t40  = t145 * t146 * t57 * t58 * 2.0;
    t495 = t143 * t147 * t57 * t58 * 2.0;
    t497 = t144 * t147 * t57 * t58 * 2.0;
    t499 = t143 * t148 * t57 * t58 * 2.0;
    t500 = t145 * t147 * t57 * t58 * 2.0;
    t503 = t146 * t147 * t57 * t58 * 2.0;
    t504 = t144 * t148 * t57 * t58 * 2.0;
    t506 = t145 * t148 * t57 * t58 * 2.0;
    t508 = t146 * t148 * t57 * t58 * 2.0;
    t57  = t147 * t148 * t57 * t58 * 2.0;
    t550 = ((((t98 * t109 * t156 * 2.0 + -t266) + t337) + t359) + t368) + t492;
    t568 = ((((t108 * t137 * t156 * 2.0 + -t268) + t330) + t27) + t456) + t504;
    t519_tmp   = t139 * t143 * t157 * t159;
    b_t519_tmp = t100 * t143 * t157 * t159;
    t519 = (((-(t100 * t139 * t156 * 2.0) + t312) + -t340) + b_t519_tmp * 2.0)
           + t519_tmp * 2.0;
    t520_tmp   = t140 * t146 * t157 * t159;
    b_t520_tmp = t107 * t146 * t157 * t159;
    t520 = (((t107 * t140 * t156 * 2.0 + t313) + -t343) + b_t520_tmp * 2.0)
           + -(t520_tmp * 2.0);
    t521_tmp   = t142 * t145 * t157 * t159;
    b_t521_tmp = t109 * t145 * t157 * t159;
    t521 = (((t109 * t142 * t156 * 2.0 + t315) + -t342) + -(b_t521_tmp * 2.0))
           + t521_tmp * 2.0;
    t522_tmp   = t137 * t144 * t157 * t159;
    b_t522_tmp = t98 * t144 * t157 * t159;
    t522 = (((-(t98 * t137 * t156 * 2.0) + t310) + -t341) + -(b_t522_tmp * 2.0))
           + -(t522_tmp * 2.0);
    t523_tmp   = t138 * t147 * t157 * t159;
    b_t523_tmp = t99 * t147 * t157 * t159;
    t523 = (((-(t99 * t138 * t156 * 2.0) + t311) + -t345) + b_t523_tmp * 2.0) + t523_tmp * 2.0;
    t524_tmp   = t141 * t148 * t157 * t159;
    b_t524_tmp = t108 * t148 * t157 * t159;
    t524 = (((t108 * t141 * t156 * 2.0 + t314) + -t348) + -(b_t524_tmp * 2.0))
           + t524_tmp * 2.0;
    t525 = (((t98 * t100 * t156 * 2.0 + t299) + t65) + -t36) + -t47;
    t526 = (((t107 * t109 * t156 * 2.0 + t302) + t38) + -t28) + -t40;
    t527 = (((-(t98 * t99 * t156 * 2.0) + t300) + t377) + -t356) + t497;
    t528 = (((-(t99 * t100 * t156 * 2.0) + t298) + t353) + t382) + -t495;
    t529 = (((-(t107 * t108 * t156 * 2.0) + t303) + t374) + -t403) + t508;
    t530 = (((-(t108 * t109 * t156 * 2.0) + t301) + -t371) + -t408) + -t506;
    t531 = (((t98 * t107 * t156 * 2.0 + t322) + t54) + -t53) + -t12;
    t532 = (((t100 * t109 * t156 * 2.0 + t59) + t55) + -t56) + -t15;
    t533 = (((t99 * t108 * t156 * 2.0 + t323) + t101) + -t103) + -t57;
    t534 = (((t98 * t140 * t156 * 2.0 + -t322) + t53) + t16) + t12;
    t535 = (((-(t107 * t137 * t156 * 2.0) + -t322) + -t54) + t11) + t12;
    t536 = (((t100 * t142 * t156 * 2.0 + -t59) + -t55) + -t105) + t15;
    t537 = (((-(t109 * t139 * t156 * 2.0) + -t59) + t56) + -t14) + t15;
    t538 = (((t99 * t141 * t156 * 2.0 + -t323) + -t101) + -t13) + t57;
    t539 = (((-(t108 * t138 * t156 * 2.0) + -t323) + t103) + -t26) + t57;
    t540 = (((t137 * t139 * t156 * 2.0 + t299) + t37) + -t73) + -t47;
    t148 = (((t140 * t142 * t156 * 2.0 + t302) + t39) + -t35) + -t40;
    t542 = (((-(t137 * t138 * t156 * 2.0) + t300) + t446) + -t424) + t497;
    t543 = (((-(t138 * t139 * t156 * 2.0) + t298) + t423) + t451) + -t495;
    t544 = (((-(t140 * t141 * t156 * 2.0) + t303) + t472) + -t442) + t508;
    t53  = (((-(t141 * t142 * t156 * 2.0) + t301) + t441) + t477) + -t506;
    t157 = (((-(t139 * t142 * t156 * 2.0) + t59) + t105) + t14) + -t15;
    t159 = (((-(t137 * t140 * t156 * 2.0) + t322) + -t16) + -t11) + -t12;
    t147 = (((-(t138 * t141 * t156 * 2.0) + t323) + t13) + t26) + -t57;
    t146 = ((((t100 * t107 * t156 * 2.0 + t266) + t327) + -t358) + -t369) + t491;
    t145 = ((((-(t99 * t107 * t156 * 2.0) + -t265) + t329) + t367) + t386) + -t503;
    t144 = ((((-(t100 * t108 * t156 * 2.0) + -t267) + t325) + t360) + -t399) + t499;
    t143 = ((((-(t99 * t109 * t156 * 2.0) + t267) + t335) + -t362) + t398) + t500;
    t52 = ((((-(t98 * t108 * t156 * 2.0) + t265) + t339) + -t27) + -t387) + -t504;
    t51 = ((((t109 * t140 * t156 * 2.0 + -t278) + -t302) + t28) + t35) + t40;
    t50 = ((((-(t98 * t139 * t156 * 2.0) + t263) + -t299) + t36) + -t37) + t47;
    t49 = ((((t107 * t142 * t156 * 2.0 + t278) + -t302) + -t38) + -t39) + t40;
    t48 = ((((-(t100 * t137 * t156 * 2.0) + -t263) + -t299) + -t65) + t73) + t47;
    t47 = ((((t99 * t137 * t156 * 2.0 + t262) + -t300) + t356) + -t446) + -t497;
    t73 = ((((t100 * t138 * t156 * 2.0 + t264) + -t298) + -t382) + -t423) + t495;
    t65 = ((((-(t109 * t141 * t156 * 2.0) + t279) + -t301) + t408) + -t441) + t506;
    t59 = ((((t98 * t138 * t156 * 2.0 + -t262) + -t300) + -t377) + t424) + -t497;
    t40 = ((((t99 * t139 * t156 * 2.0 + -t264) + -t298) + -t353) + -t451) + t495;
    t39 = ((((-(t107 * t141 * t156 * 2.0) + -t277) + -t303) + t403) + t442) + -t508;
    t38 = ((((-(t108 * t142 * t156 * 2.0) + -t279) + -t301) + t371) + -t477) + t506;
    t37 = ((((-(t108 * t140 * t156 * 2.0) + t277) + -t303) + -t374) + -t472) + -t508;
    t36 = ((((t98 * t142 * t156 * 2.0 + t271) + t328) + -t359) + t437) + -t492;
    t35 = ((((-(t109 * t137 * t156 * 2.0) + t270) + t328) + -t368) + -t428) + -t492;
    t28 = ((((t100 * t140 * t156 * 2.0 + -t271) + -t327) + t369) + -t427) + -t491;
    t27 = ((((-(t98 * t141 * t156 * 2.0) + -t269) + t330) + t387) + -t433) + t504;
    t26 = ((((t109 * t138 * t156 * 2.0 + -t272) + t326) + -t398) + t432) + -t500;
    t13 = ((((-(t107 * t139 * t156 * 2.0) + -t270) + -t327) + t358) + t438) + -t491;
    t12 = ((((-(t99 * t142 * t156 * 2.0) + -t273) + t326) + t362) + t467) + -t500;
    t11 = ((((-(t99 * t140 * t156 * 2.0) + t269) + -t329) + -t367) + t455) + t503;
    t16 = ((((t107 * t138 * t156 * 2.0 + t268) + -t329) + -t386) + -t434) + t503;
    t15 = ((((-(t100 * t141 * t156 * 2.0) + t273) + -t325) + t399) + t431) + -t499;
    t14 = ((((t108 * t139 * t156 * 2.0 + t272) + -t325) + -t360) + t468) + -t499;
    t105 = ((((-(t139 * t140 * t156 * 2.0) + t275) + t327) + t427) + -t438) + t491;
    t103 = ((((t138 * t140 * t156 * 2.0 + -t274) + t329) + t434) + -t455) + -t503;
    t101 = ((((-(t137 * t142 * t156 * 2.0) + -t275) + t337) + t428) + -t437) + t492;
    t58 = ((((t139 * t141 * t156 * 2.0 + -t276) + t325) + -t431) + -t468) + t499;
    t57 = ((((t137 * t141 * t156 * 2.0 + t274) + t339) + t433) + -t456) + -t504;
    t56 = ((((t138 * t142 * t156 * 2.0 + t276) + t335) + -t432) + -t467) + t500;
    t55 = -t315 + t342;
    H[0]   = (t55 + t142 * t142 * t156 * 2.0) - t521_tmp * 4.0;
    H[1]   = t53;
    H[2]   = t148;
    H[3]   = t521;
    H[4]   = t38;
    H[5]   = t49;
    H[6]   = t157;
    H[7]   = t56;
    H[8]   = t101;
    H[9]   = t536;
    H[10]  = t12;
    H[11]  = t36;
    H[12]  = t53;
    t54    = -t314 + t348;
    H[13]  = (t54 + t141 * t141 * t156 * 2.0) - t524_tmp * 4.0;
    H[14]  = t544;
    H[15]  = t65;
    H[16]  = t524;
    H[17]  = t39;
    H[18]  = t58;
    H[19]  = t147;
    H[20]  = t57;
    H[21]  = t15;
    H[22]  = t538;
    H[23]  = t27;
    H[24]  = t148;
    H[25]  = t544;
    t53    = -t313 + t343;
    H[26]  = (t53 + t140 * t140 * t156 * 2.0) + t520_tmp * 4.0;
    H[27]  = t51;
    H[28]  = t37;
    H[29]  = t520;
    H[30]  = t105;
    H[31]  = t103;
    H[32]  = t159;
    H[33]  = t28;
    H[34]  = t11;
    H[35]  = t534;
    H[36]  = t521;
    H[37]  = t65;
    H[38]  = t51;
    H[39]  = (t55 + t109 * t109 * t156 * 2.0) + b_t521_tmp * 4.0;
    H[40]  = t530;
    H[41]  = t526;
    H[42]  = t537;
    H[43]  = t26;
    H[44]  = t35;
    H[45]  = t532;
    H[46]  = t143;
    H[47]  = t550;
    H[48]  = t38;
    H[49]  = t524;
    H[50]  = t37;
    H[51]  = t530;
    H[52]  = (t54 + t108 * t108 * t156 * 2.0) + b_t524_tmp * 4.0;
    H[53]  = t529;
    H[54]  = t14;
    H[55]  = t539;
    H[56]  = t568;
    H[57]  = t144;
    H[58]  = t533;
    H[59]  = t52;
    H[60]  = t49;
    H[61]  = t39;
    H[62]  = t520;
    H[63]  = t526;
    H[64]  = t529;
    H[65]  = (t53 + t107 * t107 * t156 * 2.0) - b_t520_tmp * 4.0;
    H[66]  = t13;
    H[67]  = t16;
    H[68]  = t535;
    H[69]  = t146;
    H[70]  = t145;
    H[71]  = t531;
    H[72]  = t157;
    H[73]  = t58;
    H[74]  = t105;
    H[75]  = t537;
    H[76]  = t14;
    H[77]  = t13;
    t55    = -t312 + t340;
    H[78]  = (t55 + t139 * t139 * t156 * 2.0) - t519_tmp * 4.0;
    H[79]  = t543;
    H[80]  = t540;
    H[81]  = t519;
    H[82]  = t40;
    H[83]  = t50;
    H[84]  = t56;
    H[85]  = t147;
    H[86]  = t103;
    H[87]  = t26;
    H[88]  = t539;
    H[89]  = t16;
    H[90]  = t543;
    t54    = -t311 + t345;
    H[91]  = (t54 + t138 * t138 * t156 * 2.0) - t523_tmp * 4.0;
    H[92]  = t542;
    H[93]  = t73;
    H[94]  = t523;
    H[95]  = t59;
    H[96]  = t101;
    H[97]  = t57;
    H[98]  = t159;
    H[99]  = t35;
    H[100] = t568;
    H[101] = t535;
    H[102] = t540;
    H[103] = t542;
    t53    = -t310 + t341;
    H[104] = (t53 + t137 * t137 * t156 * 2.0) + t522_tmp * 4.0;
    H[105] = t48;
    H[106] = t47;
    H[107] = t522;
    H[108] = t536;
    H[109] = t15;
    H[110] = t28;
    H[111] = t532;
    H[112] = t144;
    H[113] = t146;
    H[114] = t519;
    H[115] = t73;
    H[116] = t48;
    H[117] = (t55 + t100 * t100 * t156 * 2.0) - b_t519_tmp * 4.0;
    H[118] = t528;
    H[119] = t525;
    H[120] = t12;
    H[121] = t538;
    H[122] = t11;
    H[123] = t143;
    H[124] = t533;
    H[125] = t145;
    H[126] = t40;
    H[127] = t523;
    H[128] = t47;
    H[129] = t528;
    H[130] = (t54 + t99 * t99 * t156 * 2.0) - b_t523_tmp * 4.0;
    H[131] = t527;
    H[132] = t36;
    H[133] = t27;
    H[134] = t534;
    H[135] = t550;
    H[136] = t52;
    H[137] = t531;
    H[138] = t50;
    H[139] = t59;
    H[140] = t522;
    H[141] = t525;
    H[142] = t527;
    H[143] = (t53 + t98 * t98 * t156 * 2.0) + b_t522_tmp * 4.0;
}
}  // namespace uipc::backend::cuda::distance::details


namespace uipc::backend::cuda::distance
{
template <typename T>
MUDA_GENERIC void edge_edge_distance2(const Eigen::Vector<T, 3>& ea0,
                                      const Eigen::Vector<T, 3>& ea1,
                                      const Eigen::Vector<T, 3>& eb0,
                                      const Eigen::Vector<T, 3>& eb1,
                                      T&                         dist2)
{
    Eigen::Matrix<T, 3, 1> b = Eigen::Matrix<T, 3, 1>(ea1 - ea0).cross(eb1 - eb0);
    T aTb = Eigen::Matrix<T, 3, 1>(eb0 - ea0).dot(b);
    dist2 = aTb * aTb / b.squaredNorm();
}

template <typename T>
MUDA_GENERIC void edge_edge_distance2_gradient(const Eigen::Vector<T, 3>& ea0,
                                               const Eigen::Vector<T, 3>& ea1,
                                               const Eigen::Vector<T, 3>& eb0,
                                               const Eigen::Vector<T, 3>& eb1,
                                               Eigen::Vector<T, 12>&      grad)
{
    details::g_EE(ea0[0],
                  ea0[1],
                  ea0[2],
                  ea1[0],
                  ea1[1],
                  ea1[2],
                  eb0[0],
                  eb0[1],
                  eb0[2],
                  eb1[0],
                  eb1[1],
                  eb1[2],
                  grad.data());
}

template <typename T>
MUDA_GENERIC void edge_edge_distance2_hessian(const Eigen::Vector<T, 3>& ea0,
                                              const Eigen::Vector<T, 3>& ea1,
                                              const Eigen::Vector<T, 3>& eb0,
                                              const Eigen::Vector<T, 3>& eb1,
                                              Eigen::Matrix<T, 12, 12>& Hessian)
{
    details::H_EE(ea0[0],
                  ea0[1],
                  ea0[2],
                  ea1[0],
                  ea1[1],
                  ea1[2],
                  eb0[0],
                  eb0[1],
                  eb0[2],
                  eb1[0],
                  eb1[1],
                  eb1[2],
                  Hessian.data());
}

}  // namespace uipc::backend::cuda::distance