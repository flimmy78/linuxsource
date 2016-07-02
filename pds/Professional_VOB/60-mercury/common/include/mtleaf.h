/******************************************************************************
 ******************************************************************************
 **** This file was automatically generated by Wind River Systems
 **** Emissary SNMP MIB Compiler, version 7.0.
 **** This file was generated using the -leaf switch.
 **** 
 **** This file #defines C preprocessor macros providing a variety of
 **** information for the leaf objects in the MIB.
 **** 
 **** The file includes a LEAF_xxx macro for each leaf object in the
 **** MIB (xxx is replaced by the object's name).  The value of the
 **** LEAF_xxx macro is the final component of the object's object
 **** identifier.
 **** 
 **** If the object's SYNTAX clause included named INTEGER values,
 **** then there is a VAL_xxx_yyy macro for each named value (xxx is
 **** replaced by the object's name and yyy by the value's name).  The
 **** value of the VAL_xxx_yyy macro is the value associated with the
 **** named value.
 **** 
 **** If the object's SYNTAX clause specified a set of range limitations
 **** for the value of the object, then there are one or more sets of
 **** MIN_xxx and MAX_xxx macros specifying the lower and upper bound of
 **** each range limitation.
 **** 
 **** If the object's SYNTAX clause specified a set of size constraints
 **** for the value of the object, then there are one or more sets of
 **** MINSIZE_xxx and MAXSIZE_xxx macros specifying the lower and upper
 **** bound of each size constraint.  (If the size constraint is a single
 **** value rather than a range then the MINSIZE_xxx and MAXSIZE_xxx
 **** macros are replaced by a single SIZE_xxx macro.)
 **** 
 **** DO NOT MODIFY THIS FILE BY HAND.
 **** 
 **** Last build date: Thu Nov 20 10:09:45 2003
 **** from files:
 ****  kdv.smi, kdvmt.mib
 ******************************************************************************
 ******************************************************************************
 */

#define LEAF_mtsysState	1
#define VAL_mtsysState_running	1L
#define VAL_mtsysState_reboot	2L
#define VAL_mtsysState_standby	3L
#define LEAF_mtsysTime	2
#define SIZE_mtsysTime	14L
#define LEAF_mtsysFtpFileName	3
#define MINSIZE_mtsysFtpFileName	0L
#define MAXSIZE_mtsysFtpFileName	255L
#define LEAF_mtsysConfigVersion	4
#define SIZE_mtsysConfigVersion	14L
#define LEAF_mtsysSoftwareVersion	5
#define MINSIZE_mtsysSoftwareVersion	0L
#define MAXSIZE_mtsysSoftwareVersion	255L
#define LEAF_mtsysHardwareType	6
#define VAL_mtsysHardwareType_pc	1L
#define VAL_mtsysHardwareType_embed	2L
#define LEAF_mtsysFTPUserName	7
#define MINSIZE_mtsysFTPUserName	0L
#define MAXSIZE_mtsysFTPUserName	32L
#define LEAF_mtsysFTPPassword	8
#define MINSIZE_mtsysFTPPassword	0L
#define MAXSIZE_mtsysFTPPassword	32L
#define LEAF_mtnetNmIpIndex	1
#define LEAF_mtnetVcIpIndex	2
#define LEAF_mtnetGwIpIndex	3
#define LEAF_mtnetGKIpAddr	4
#define LEAF_mtnetBandwidth	5
#define MIN_mtnetBandwidth	256L
#define MAX_mtnetBandwidth	8192L
#define LEAF_mtnetRcvStartPort	6
#define LEAF_mtnetSendStartPort	7
#define LEAF_mtnetTrapRcvEntIpAddr	1
#define LEAF_mtnetTrapRcvEntCommunity	2
#define MINSIZE_mtnetTrapRcvEntCommunity	0L
#define MAXSIZE_mtnetTrapRcvEntCommunity	31L
#define LEAF_mtnetTrapRcvEntExist	3
#define VAL_mtnetTrapRcvEntExist_true	1L
#define VAL_mtnetTrapRcvEntExist_false	2L
#define LEAF_mtnetTrapEntryAddIp	2
#define LEAF_mtnetTrapEntryAddCommunity	3
#define MINSIZE_mtnetTrapEntryAddCommunity	0L
#define MAXSIZE_mtnetTrapEntryAddCommunity	255L
#define LEAF_mtnetTrapEntryAddEnable	4
#define LEAF_mtnetEthernetCardEntIndex	1
#define LEAF_mtnetEthernetCardEntType	2
#define VAL_mtnetEthernetCardEntType_ethernetcard	1L
#define VAL_mtnetEthernetCardEntType_ipoh	2L
#define LEAF_mtnetEthernetCardEntIpAddr	3
#define LEAF_mtnetEthernetCardEntMask	4
#define LEAF_mtnetEthernetCardEntPhyAddr	5
#define LEAF_mtnetEthernetCardEntExist	6
#define VAL_mtnetEthernetCardEntExist_true	1L
#define VAL_mtnetEthernetCardEntExist_false	2L
#define LEAF_mteqpCameraEntId	1
#define LEAF_mteqpCameraEntType	2
#define VAL_mteqpCameraEntType_sony	1L
#define VAL_mteqpCameraEntType_pelco	2L
#define VAL_mteqpCameraEntType_samsung	3L
#define VAL_mteqpCameraEntType_general	4L
#define LEAF_mteqpCameraEntSvrIpAddr	3
#define LEAF_mteqpCameraEntPort	4
#define LEAF_mteqpCameraEntExist	5
#define VAL_mteqpCameraEntExist_true	1L
#define VAL_mteqpCameraEntExist_false	2L
#define LEAF_mteqpMatrixEntId	1
#define LEAF_mteqpMatrixEntType	2
#define VAL_mteqpMatrixEntType_internal	1L
#define VAL_mteqpMatrixEntType_vas	2L
#define VAL_mteqpMatrixEntType_extron	3L
#define LEAF_mteqpMatrixEntSvrIpAddr	3
#define LEAF_mteqpMatrixEntPort	4
#define LEAF_mteqpMatrixEntExist	5
#define VAL_mteqpMatrixEntExist_true	1L
#define VAL_mteqpMatrixEntExist_false	2L
#define LEAF_mteqpNetEncoderId	1
#define LEAF_mtVideoEncSource	1
#define VAL_mtVideoEncSource_comp	1L
#define VAL_mtVideoEncSource_s_video	2L
#define LEAF_mtVideoEncSystem	2
#define VAL_mtVideoEncSystem_pal	1L
#define VAL_mtVideoEncSystem_ntsc	2L
#define LEAF_mtVideoEncFormat	3
#define VAL_mtVideoEncFormat_h261	1L
#define VAL_mtVideoEncFormat_h263	2L
#define VAL_mtVideoEncFormat_mpeg4	3L
#define LEAF_mtVideoEncBitRate	4
#define LEAF_mtVideoEncResolution	5
#define VAL_mtVideoEncResolution_res_160_120	1L
#define VAL_mtVideoEncResolution_res_176_144	2L
#define VAL_mtVideoEncResolution_res_320_240	3L
#define VAL_mtVideoEncResolution_res_352_288	4L
#define VAL_mtVideoEncResolution_res_640_480	5L
#define VAL_mtVideoEncResolution_res_720_576	6L
#define LEAF_mtVideoEncFrameRate	6
#define LEAF_mtVideoEncIKeyRate	7
#define LEAF_mtVideoEncQualMaxValue	8
#define LEAF_mtVideoEncQualMinValue	9
#define LEAF_mtVideoEncImageQuality	10
#define LEAF_mtAudioEncSource	1
#define VAL_mtAudioEncSource_line	1L
#define VAL_mtAudioEncSource_mic	2L
#define LEAF_mtAudioEncFormat	2
#define VAL_mtAudioEncFormat_mp3_1	1L
#define VAL_mtAudioEncFormat_mp3_2	2L
#define VAL_mtAudioEncFormat_mp3_3	3L
#define VAL_mtAudioEncFormat_mp3_4	4L
#define VAL_mtAudioEncFormat_g711u	5L
#define VAL_mtAudioEncFormat_g711a	6L
#define VAL_mtAudioEncFormat_g723	7L
#define VAL_mtAudioEncFormat_g729	8L
#define VAL_mtAudioEncFormat_g722	9L
#define LEAF_mtAudioEncVolume	3
#define LEAF_mtAudioAEC	4
#define VAL_mtAudioAEC_enable	1L
#define VAL_mtAudioAEC_disable	2L
#define LEAF_mtpfmAlarmStamp	1
#define LEAF_mtpfmAlarmEntSerialNo	1
#define LEAF_mtpfmAlarmEntAlarmCode	2
#define LEAF_mtpfmAlarmEntObjType	3
#define LEAF_mtpfmAlarmEntObject	4
#define MINSIZE_mtpfmAlarmEntObject	0L
#define MAXSIZE_mtpfmAlarmEntObject	1L
#define LEAF_mtpfmAlarmEntTime	5
#define SIZE_mtpfmAlarmEntTime	19L
#define LEAF_mtpfmEncoderVideoFrameRate	1
#define LEAF_mtpfmEncoderVideoBitRate	2
#define LEAF_mtpfmEncoderAudioBitRate	3
#define LEAF_mtpfmEncoderVideoPackLose	4
#define LEAF_mtpfmEncoderVideoPackError	5
#define LEAF_mtpfmEncoderAudioPackLose	6
#define LEAF_mtpfmEncoderAudioPackError	7
#define LEAF_mtpfmDecoderVideoFrameRate	1
#define LEAF_mtpfmDecoderVideoBitRate	2
#define LEAF_mtpfmDecoderAudioBitRate	3
#define LEAF_mtpfmDecoderVideoRecvFrame	4
#define LEAF_mtpfmDecoderAudioRecvFrame	5
#define LEAF_mtpfmDecoderVideoLoseFrame	6
#define LEAF_mtpfmDecoderAudioLoseFrame	7
#define LEAF_mtpfmDecoderPackError	8
#define LEAF_mtpfmDecoderIndexLose	9
#define LEAF_mtpfmDecoderSizeLose	10
#define LEAF_mtpfmDecoderFullLose	11
#define LEAF_mtpfmDSP1FanSpeed	1
#define LEAF_mtpfmDSP2FanSpeed	2
#define LEAF_mtpfmDSP3FanSpeed	3
#define LEAF_mtpfmSYS1FanSpeed	4
#define LEAF_mtpfmSYS2FanSpeed	5
#define LEAF_mtpfmLedState	1
#define LEAF_mtAlias	1
#define MINSIZE_mtAlias	0L
#define MAXSIZE_mtAlias	31L
#define LEAF_mtE164Number	2
#define MINSIZE_mtE164Number	0L
#define MAXSIZE_mtE164Number	9L
#define LEAF_mtType	3
#define VAL_mtType_receive_transmit	1L
#define VAL_mtType_receive_only	2L
#define VAL_mtType_transmit_only	3L
#define LEAF_mtPosition	4
#define VAL_mtPosition_primary	1L
#define VAL_mtPosition_audit	2L
#define LEAF_mtDisplayLabelOnOff	1
#define VAL_mtDisplayLabelOnOff_on	1L
#define VAL_mtDisplayLabelOnOff_off	2L
#define LEAF_mtDisplayLabelMode	2
#define VAL_mtDisplayLabelMode_righttop	1L
#define VAL_mtDisplayLabelMode_rightbottom	2L
#define VAL_mtDisplayLabelMode_lefttop	3L
#define VAL_mtDisplayLabelMode_leftbottom	4L
#define LEAF_mtDisplayPIPMode	3
#define VAL_mtDisplayPIPMode_righttop	1L
#define VAL_mtDisplayPIPMode_rightbottom	2L
#define VAL_mtDisplayPIPMode_lefttop	3L
#define VAL_mtDisplayPIPMode_leftbottom	4L
#define LEAF_mtAnswerMode	1
#define VAL_mtAnswerMode_auto	1L
#define VAL_mtAnswerMode_hand	2L
#define VAL_mtAnswerMode_do_not_interrupt	3L
#define LEAF_mtCallMode	2
#define VAL_mtCallMode_auto	1L
#define VAL_mtCallMode_hand	2L
#define LEAF_mtAutoCallIpAddr	3