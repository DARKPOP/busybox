/*
 * applets.h - a listing of all busybox applets.
 *
 * If you write a new applet, you need to add an entry to this list to make
 * busybox aware of it.
 *
 * It is CRUCIAL that this listing be kept in ascii order, otherwise the binary
 * search lookup contributed by Gaute B Strokkenes stops working. If you value
 * your kneecaps, you'll be sure to *make sure* that any changes made to this
 * file result in the listing remaining in ascii order. You have been warned.
 */

#undef APPLET
#undef APPLET_ODDNAME
#undef APPLET_NOUSAGE


#if defined(PROTOTYPES)
  #define APPLET(a,b,c) extern int b(int argc, char **argv);
  #define APPLET_NOUSAGE(a,b,c) extern int b(int argc, char **argv);
  #define APPLET_ODDNAME(a,b,c,d) extern int b(int argc, char **argv);
  extern const char usage_messages[];
#elif defined(MAKE_USAGE)
  #ifdef CONFIG_FEATURE_VERBOSE_USAGE
    #define APPLET(a,b,c) a##_trivial_usage "\n\n" a##_full_usage "\0"
    #define APPLET_NOUSAGE(a,b,c) "\0"
    #define APPLET_ODDNAME(a,b,c,d) d##_trivial_usage "\n\n" d##_full_usage "\0"
  #else
    #define APPLET(a,b,c) a##_trivial_usage "\0"
    #define APPLET_NOUSAGE(a,b,c) "\0"
    #define APPLET_ODDNAME(a,b,c,d) d##_trivial_usage "\0"
  #endif
#elif defined(MAKE_LINKS)
#  define APPLET(a,b,c) LINK c a
#  define APPLET_NOUSAGE(a,b,c) LINK c a
#  define APPLET_ODDNAME(a,b,c,d) LINK c a
#else
  const struct BB_applet applets[] = {
  #define APPLET(a,b,c) {#a,b,c},
  #define APPLET_NOUSAGE(a,b,c) {a,b,c},
  #define APPLET_ODDNAME(a,b,c,d) {a,b,c},
#endif



#ifdef CONFIG_TEST
	APPLET_NOUSAGE("[", test_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_ADDGROUP
	APPLET(addgroup, addgroup_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_ADDUSER
	APPLET(adduser, adduser_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_ADJTIMEX
	APPLET(adjtimex, adjtimex_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_AR
	APPLET(ar, ar_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_ASH
	APPLET_NOUSAGE("ash", ash_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_BASENAME
	APPLET(basename, basename_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_BUNZIP2
	APPLET(bunzip2, bunzip2_main, _BB_DIR_USR_BIN)
#endif
	APPLET_NOUSAGE("busybox", busybox_main, _BB_DIR_BIN)
#ifdef CONFIG_BUNZIP2
	APPLET(bzcat, bunzip2_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_CAT
	APPLET(cat, cat_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_CHGRP
	APPLET(chgrp, chgrp_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_CHMOD
	APPLET(chmod, chmod_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_CHOWN
	APPLET(chown, chown_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_CHROOT
	APPLET(chroot, chroot_main, _BB_DIR_USR_SBIN)
#endif
#ifdef CONFIG_CHVT
	APPLET(chvt, chvt_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_CLEAR
	APPLET(clear, clear_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_CMP
	APPLET(cmp, cmp_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_CP
	APPLET(cp, cp_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_CPIO
	APPLET(cpio, cpio_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_CUT
	APPLET(cut, cut_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DATE
	APPLET(date, date_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DC
	APPLET(dc, dc_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DD
	APPLET(dd, dd_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DEALLOCVT
	APPLET(deallocvt, deallocvt_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DELGROUP
	APPLET(delgroup, delgroup_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DELUSER
	APPLET(deluser, deluser_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DF
	APPLET(df, df_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DIRNAME
	APPLET(dirname, dirname_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DMESG
	APPLET(dmesg, dmesg_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DOS2UNIX
	APPLET(dos2unix, dos2unix_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DPKG
	APPLET(dpkg, dpkg_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DPKG_DEB
	APPLET_ODDNAME("dpkg-deb", dpkg_deb_main, _BB_DIR_USR_BIN, dpkg_deb)
#endif
#ifdef CONFIG_DU
	APPLET(du, du_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_DUMPKMAP
	APPLET(dumpkmap, dumpkmap_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_DUTMP
	APPLET(dutmp, dutmp_main, _BB_DIR_USR_SBIN)
#endif
#ifdef CONFIG_ECHO
	APPLET(echo, echo_main, _BB_DIR_BIN)
#endif
#if defined(CONFIG_FEATURE_GREP_EGREP_ALIAS)
	APPLET_NOUSAGE("egrep", grep_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_ENV
	APPLET(env, env_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_EXPR
	APPLET(expr, expr_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_FALSE
	APPLET(false, false_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_FBSET
	APPLET(fbset, fbset_main, _BB_DIR_USR_SBIN)
#endif
#ifdef CONFIG_FDFLUSH
	APPLET(fdflush, fdflush_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_FIND
	APPLET(find, find_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_FREE
	APPLET(free, free_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_FREERAMDISK
	APPLET(freeramdisk, freeramdisk_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_FSCK_MINIX
	APPLET_ODDNAME("fsck.minix", fsck_minix_main, _BB_DIR_SBIN, fsck_minix)
#endif
#ifdef CONFIG_GETOPT
	APPLET(getopt, getopt_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_GETTY
	APPLET(getty, getty_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_GREP
	APPLET(grep, grep_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_GUNZIP
	APPLET(gunzip, gunzip_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_GZIP
	APPLET(gzip, gzip_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_HALT
	APPLET(halt, halt_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_HEAD
	APPLET(head, head_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_HEXDUMP
	APPLET(hexdump, hexdump_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_HOSTID
	APPLET(hostid, hostid_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_HOSTNAME
	APPLET(hostname, hostname_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_HUSH
	APPLET_NOUSAGE("hush", hush_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_ID
	APPLET(id, id_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_IFCONFIG
	APPLET(ifconfig, ifconfig_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_INIT
	APPLET(init, init_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_INSMOD
	APPLET(insmod, insmod_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_KILL
	APPLET(kill, kill_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_KILLALL
	APPLET(killall, kill_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_KLOGD
	APPLET(klogd, klogd_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_LASH
	APPLET(lash, lash_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_LENGTH
	APPLET(length, length_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_FEATURE_INITRD
	APPLET_NOUSAGE("linuxrc", init_main, _BB_DIR_ROOT)
#endif
#ifdef CONFIG_LN
	APPLET(ln, ln_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_LOADACM
	APPLET(loadacm, loadacm_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_LOADFONT
	APPLET(loadfont, loadfont_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_LOADKMAP
	APPLET(loadkmap, loadkmap_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_LOGGER
	APPLET(logger, logger_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_LOGNAME
	APPLET(logname, logname_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_LOGREAD
	APPLET(logread, logread_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_LS
	APPLET(ls, ls_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_LSMOD
	APPLET(lsmod, lsmod_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_MAKEDEVS
	APPLET(makedevs, makedevs_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_MD5SUM
	APPLET(md5sum, md5sum_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_MKDIR
	APPLET(mkdir, mkdir_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MKFIFO
	APPLET(mkfifo, mkfifo_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_MKFS_MINIX
	APPLET_ODDNAME("mkfs.minix", mkfs_minix_main, _BB_DIR_SBIN, mkfs_minix)
#endif
#ifdef CONFIG_MKNOD
	APPLET(mknod, mknod_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MKSWAP
	APPLET(mkswap, mkswap_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_MKTEMP
	APPLET(mktemp, mktemp_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MODPROBE
	APPLET(modprobe, modprobe_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_MORE
	APPLET(more, more_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MOUNT
	APPLET(mount, mount_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MSH
	APPLET_NOUSAGE("msh", msh_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MT
	APPLET(mt, mt_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_MV
	APPLET(mv, mv_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_NC
	APPLET(nc, nc_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_NETSTAT
	APPLET(netstat, netstat_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_NSLOOKUP
	APPLET(nslookup, nslookup_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_OD
	APPLET(od, od_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_PIDOF
	APPLET(pidof, pidof_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_PING
	APPLET(ping, ping_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_PIVOT_ROOT
 	APPLET(pivot_root, pivot_root_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_POWEROFF
	APPLET(poweroff, poweroff_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_PRINTF
	APPLET(printf, printf_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_PS
	APPLET(ps, ps_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_PWD
	APPLET(pwd, pwd_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_RDATE
	APPLET(rdate, rdate_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_READLINK
	APPLET(readlink, readlink_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_REBOOT
	APPLET(reboot, reboot_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_RENICE
	APPLET(renice, renice_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_RESET
	APPLET(reset, reset_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_RM
	APPLET(rm, rm_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_RMDIR
	APPLET(rmdir, rmdir_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_RMMOD
	APPLET(rmmod, rmmod_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_ROUTE
 	APPLET(route, route_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_RPM2CPIO
	APPLET(rpm2cpio, rpm2cpio_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_RUN_PARTS
	APPLET_ODDNAME("run-parts", run_parts_main, _BB_DIR_BIN, run_parts)
#endif	
#ifdef CONFIG_SED
	APPLET(sed, sed_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_SETKEYCODES
	APPLET(setkeycodes, setkeycodes_main, _BB_DIR_USR_BIN)
#endif
#if defined(CONFIG_FEATURE_SH_IS_ASH) && defined(CONFIG_ASH)
	APPLET_NOUSAGE("sh", ash_main, _BB_DIR_BIN)
#elif defined(CONFIG_FEATURE_SH_IS_HUSH) && defined(CONFIG_HUSH)
	APPLET_NOUSAGE("sh", hush_main, _BB_DIR_BIN)
#elif defined(CONFIG_FEATURE_SH_IS_LASH) && defined(CONFIG_LASH)
	APPLET_NOUSAGE("sh", lash_main, _BB_DIR_BIN)
#elif defined(CONFIG_FEATURE_SH_IS_MSH) && defined(CONFIG_MSH)
	APPLET_NOUSAGE("sh", msh_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_SLEEP
	APPLET(sleep, sleep_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_SORT
	APPLET(sort, sort_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_START_STOP_DAEMON
    APPLET_ODDNAME("start-stop-daemon", start_stop_daemon_main, _BB_DIR_SBIN, start_stop_daemon)
#endif
#ifdef CONFIG_STTY
	APPLET(stty, stty_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_SWAPONOFF
	APPLET(swapoff, swap_on_off_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_SWAPONOFF
	APPLET(swapon, swap_on_off_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_SYNC
	APPLET(sync, sync_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_SYSLOGD
	APPLET(syslogd, syslogd_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_TAIL
	APPLET(tail, tail_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TAR
	APPLET(tar, tar_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_TEE
	APPLET(tee, tee_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TELNET
	APPLET(telnet, telnet_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TEST
	APPLET(test, test_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TFTP
	APPLET(tftp, tftp_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TIME
	APPLET(time, time_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TOUCH
	APPLET(touch, touch_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_TR
	APPLET(tr, tr_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TRACEROUTE
	APPLET(traceroute, traceroute_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_TRUE
	APPLET(true, true_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_TTY
	APPLET(tty, tty_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_UMOUNT
	APPLET(umount, umount_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_UNAME
	APPLET(uname, uname_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_UNIQ
	APPLET(uniq, uniq_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_UNIX2DOS
	APPLET(unix2dos, dos2unix_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_UPDATE
	APPLET(update, update_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_UPTIME
	APPLET(uptime, uptime_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_USLEEP
	APPLET(usleep, usleep_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_UUDECODE
	APPLET(uudecode, uudecode_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_UUENCODE
	APPLET(uuencode, uuencode_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_VI
	APPLET(vi, vi_main, _BB_DIR_BIN)
#endif
#ifdef CONFIG_WATCHDOG
	APPLET(watchdog, watchdog_main, _BB_DIR_SBIN)
#endif
#ifdef CONFIG_WC
	APPLET(wc, wc_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_WGET
	APPLET(wget, wget_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_WHICH
	APPLET(which, which_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_WHOAMI
	APPLET(whoami, whoami_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_XARGS
	APPLET(xargs, xargs_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_YES
	APPLET(yes, yes_main, _BB_DIR_USR_BIN)
#endif
#ifdef CONFIG_GUNZIP
	APPLET(zcat, gunzip_main, _BB_DIR_BIN)
#endif

#if !defined(PROTOTYPES) && !defined(MAKE_USAGE)
	{ 0,NULL,0 }
};

#endif

