/**
 * @file /include/cmd_vel_mux/cmd_vel_subscribers.hpp
 *
 * @brief Structure for the cmd_vel_mux.
 *
 * License: BSD
 *   https://raw.github.com/yujinrobot/yujin_ocs/groovy/cmd_vel_mux/LICENSE
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef CMD_VEL_SUBSCRIBERS_HPP_
#define CMD_VEL_SUBSCRIBERS_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <yaml-cpp/yaml.h>

/*****************************************************************************
** Preprocessing
*****************************************************************************/

// move to a static const?
#define VACANT  std::numeric_limits<unsigned int>::max()

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace cmd_vel_mux {

/*****************************************************************************
** CmdVelSubscribers
*****************************************************************************/

/**
 * Pool of cmd_vel topics subscribers
 */
class CmdVelSubscribers
{
public:

  /**
   * Inner class describing an individual subscriber to a cmd_vel topic
   */
  class CmdVelSubs
  {
  public:
    unsigned int           idx;          /**< Index; assigned according to the order on YAML file */
    std::string            name;         /**< Descriptive name */
    ros::Subscriber        subs;         /**< The subscriber itself */
    std::string            topic;        /**< The name of the topic */
    ros::Timer             timer;        /**< No incoming messages timeout */
    double                 timeout;      /**< Timer's timeout, in seconds  */
    unsigned int           priority;     /**< UNIQUE integer from 0 (lowest priority) to MAX_INT */
    std::string            short_desc;   /**< Short description (optional) */
    bool                   active;       /**< Whether this source is active */

    CmdVelSubs(unsigned int idx) : idx(idx), active(false) {};

    void operator << (const YAML::Node& node);
  };

  CmdVelSubscribers() : allowed(VACANT) { }
  ~CmdVelSubscribers() { }

  std::vector<CmdVelSubs>::size_type size() { return list.size(); };
  CmdVelSubs& operator [] (unsigned int idx) { return list[idx]; };

  /**
   * @brief Configures the subscribers from a yaml file.
   *
   * @exception FileNotFoundException : yaml file not found
   * @exception YamlException : problem parsing the yaml
   * @exception EmptyCfgException : empty configuration file
   * @param node : node holding all the subscriber configuration
   */
  void configure(const YAML::Node& node);

  unsigned int allowed;

private:
  std::vector<CmdVelSubs> list;
};

} // namespace cmd_vel_mux

#endif /* CMD_VEL_SUBSCRIBERS_HPP_ */
