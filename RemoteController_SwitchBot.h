/* 
 Copyright (C) 2020 hidenorly

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef __REMOTE_CONTROLLER_SWITCH_BOT_H__
#define __REMOTE_CONTROLLER_SWITCH_BOT_H__

#include "config.h"
#if ENABLE_SWITCH_BOT_REMOTE_CONTROLLER

#include "base.h"
#include "RemoteController.h"

#ifdef __REMOTE_CONTROLLER_SWITCH_BOT_IMPL_H__
  #define SWITCH_BOT_SERVICE_UUID "CBA20D00-224D-11E6-9FB8-0002A5D5C51B"
  #define SWITCH_BOT_CHARACTERISTIC_UUID "CBA20002-224D-11E6-9FB8-0002A5D5C51B"
#endif // __REMOTE_CONTROLLER_SWITCH_BOT_IMPL_H__

#define MAX_SWITCH_BOT_DEVICES  4

class SwitchBotRemoteController : public IRemoteController
{
public:
  typedef enum
  {
    MODE_ONOFF_ON_OFF,
    MODE_ONOFF_OFF_ON,
    MODE_ON_ON,
    MODE_ON_OFF,
    MODE_OFF_ON,
    MODE_OFF_OFF,
  } MODE_SWITCH_BOT;

public:
  SwitchBotRemoteController(int id = 0, MODE_SWITCH_BOT mode = MODE_ONOFF_ON_OFF);
  virtual ~SwitchBotRemoteController();

  typedef enum
  {
    ACTION_BEGIN = 0,
    	ACTION_PRESS = ACTION_BEGIN,
    	ACTION_TURN_ON,
    	ACTION_TURN_OFF,
    ACTION_END // end of action
  } ACTION_SWITCH_BOT;
  void actionSwitchBot(ACTION_SWITCH_BOT action);

  virtual void sendKey(int keyCode);

  void setMode(MODE_SWITCH_BOT mode);
  MODE_SWITCH_BOT getMode(void);

protected:
  int mId;
  MODE_SWITCH_BOT mMode;
  static int mCountInitialized;
};


class SwitchBotUtil
{
public:
  static void saveConfig(void);
  static void loadConfig(void);
  static void setTargetBleAddr(String bleAddr, int id=0);
  static String getTargetBleAddr(int id=0);

  static String getModeString(int id=0);
  static void setModeByString(String mode, int id=0);

  static SwitchBotRemoteController::MODE_SWITCH_BOT getMode(int id=0);
  static void setMode(SwitchBotRemoteController::MODE_SWITCH_BOT mode, int id=0);

  static String _getModeString(SwitchBotRemoteController::MODE_SWITCH_BOT mode);
  static SwitchBotRemoteController::MODE_SWITCH_BOT _getModeFromString(String mode);

protected:
  static String mBleAddr[MAX_SWITCH_BOT_DEVICES];
  static SwitchBotRemoteController::MODE_SWITCH_BOT mMode[MAX_SWITCH_BOT_DEVICES];
};

#endif // ENABLE_SWITCH_BOT_REMOTE_CONTROLLER

#endif // __REMOTE_CONTROLLER_SWITCH_BOT_H__