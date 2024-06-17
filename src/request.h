/**
 * @file request.h
 * @brief Defines the Request struct.
 *
 */

#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>

/**
 * @brief Represents a web request.
 *
 * The Request struct represents a web request with properties like request ID,
 * timestamp, and IP addresses. It includes methods to display the details of
 * the request and get the request properties.
 *
 */
struct Request {
  int requestID;
  int timestamp;
  int ipIn;
  int ipOut;

  /**
   * @brief Constructs a Request object with the given ID and timestamp.
   *
   * This constructor initializes a Request object with the specified ID and
   * timestamp. It also generates random values for the `ipIn` and `ipOut`
   * member variables.
   *
   * @param id The ID of the request.
   * @param time The timestamp of the request.
   */
  Request(int id, int time) : requestID(id), timestamp(time) {
    ipIn = rand() % 100;
    ipOut = rand() % 100;
  }

  /**
   * @brief Default constructor for the Request class.
   *
   * This constructor initializes the request ID, timestamp, and IP addresses to
   * 0.
   */
  Request() {
    requestID = 0;
    timestamp = 0;
    ipIn = 0;
    ipOut = 0;
  }

  /**
   * Displays the details of the request.
   */
  void displayRequest() {
    std::cout << "Request ID: " << requestID << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "IP In: " << ipIn << std::endl;
    std::cout << "IP Out: " << ipOut << std::endl;
  }

  /**
   * Returns the timestamp of the request.
   *
   * @return The timestamp of the request.
   */
  int getTime() { return timestamp; }

  /**
   * Returns the value of the `ipIn` member variable.
   *
   * @return The value of the `ipIn` member variable.
   */
  int getIPIn() { return ipIn; }

  /**
   * @brief Get the IP Out value.
   *
   * This function returns the IP Out value.
   *
   * @return The IP Out value.
   */
  int getIPOut() { return ipOut; }

  /**
   * @brief Get the request ID.
   *
   * This function returns the ID of the request.
   *
   * @return The request ID.
   */
  int getRequestID() { return requestID; }

  /**
   * Sets the timestamp of the request.
   *
   * @param time The timestamp value to set.
   */
  void setTimestamp(int time) { timestamp = time; }

  /**
   * @brief Sets the input IP address.
   *
   * This function sets the value of the input IP address to the specified
   * value.
   *
   * @param ip The input IP address to be set.
   */
  void setIPIn(int ip) { ipIn = ip; }

  /**
   * @brief Sets the IP out value.
   *
   * This function sets the IP out value to the specified IP.
   *
   * @param ip The IP value to set.
   */
  void setIPOut(int ip) { ipOut = ip; }

  /**
   * @brief Sets the request ID.
   *
   * This function sets the request ID to the specified value.
   *
   * @param id The request ID to set.
   */
  void setRequestID(int id) { requestID = id; }
};

#endif