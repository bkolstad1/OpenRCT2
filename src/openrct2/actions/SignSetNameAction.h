/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "GameAction.h"

class SignSetNameAction final : public GameActionBase<GameCommand::SetSignName>
{
private:
    BannerIndex _bannerIndex{ BANNER_INDEX_NULL };
    std::string _name;

public:
    SignSetNameAction() = default;
    SignSetNameAction(BannerIndex bannerIndex, const std::string& name);

    void AcceptParameters(GameActionParameterVisitor& visitor) override;

    uint16_t GetActionFlags() const override;

    void Serialise(DataSerialiser& stream) override;
    GameActions::Result Query() const override;
    GameActions::Result Execute() const override;
};
