/* bzflag
 * Copyright (c) 1993 - 2008 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * HUDuiServerListItem:
 *	FILL THIS IN
 */

#ifndef	__HUDUISERVERLISTITEM_H__
#define	__HUDUISERVERLISTITEM_H__

// ancestor class
#include "HUDuiControl.h"

#include "HUDuiLabel.h"
#include "ServerItem.h"
#include <string>

class HUDuiServerListItem : public HUDuiControl {
  public:
      HUDuiServerListItem();
      HUDuiServerListItem(ServerItem item);
      ~HUDuiServerListItem();

    void setFontSize(float size);
    void setFontFace(const LocalFontFace* fontFace);
	
    void setSize(float width, float height);
    void setPosition(float x, float y);
	
    std::string getDomainName();
    std::string getServerName();
    std::string getPlayerCount();
    std::string getServerPing();

  protected:
    void doRender();

  private:
    HUDuiLabel* domainName;
    HUDuiLabel* serverName;
    HUDuiLabel* playerCount;
    HUDuiLabel* serverPing;
	
    static const float DOMAIN_PERCENTAGE;
    static const float SERVER_PERCENTAGE;
    static const float PLAYER_PERCENTAGE;
    static const float PING_PERCENTAGE;
};

#endif // __HUDuiServerListItem_H__

// Local Variables: ***
// mode: C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8