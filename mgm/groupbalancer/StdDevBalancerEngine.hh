//------------------------------------------------------------------------------
// File: StdDevBalancerEngine.hh
// Author: Abhishek Lekshmanan - CERN
//------------------------------------------------------------------------------

/************************************************************************
 * EOS - the CERN Disk Storage System                                   *
 * Copyright (C) 2022 CERN/Switzerland                                  *
 *                                                                      *
 * This program is free software: you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation, either version 3 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * This program is distributed in the hope that it will be useful,      *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 * GNU General Public License for more details.                         *
 *                                                                      *
 * You should have received a copy of the GNU General Public License    *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.*
 ************************************************************************/

#pragma once
#include <unordered_set>
#include "mgm/groupbalancer/BalancerEngine.hh"

namespace eos::mgm::group_balancer {

class StdDevBalancerEngine: public BalancerEngine
{
public:
  void recalculate() override;
  void updateGroup(const std::string& group_name) override;
  void configure(const engine_conf_t& conf) override;

  // Getters only used by GTest
  double get_min_threshold() const {
    return mMinDeviation;
  }

  double get_max_threshold() const {
    return mMaxDeviation;
  }

  std::string get_status_str(bool detail=false, bool monitoring=false) const override;
private:
  /// average filled percentage in groups
  double mAvgUsedSize;
  double mMinDeviation;
  double mMaxDeviation;
};

} // namespace eos::mgm::group_balancer
