#ifndef HEADER_VIEW
#define HEADER_VIEW

namespace zombone_engine {

/**
 * A View
 */
struct view {
  /** X coordinate of the upper left corner of the view
   */
  int x;
  /** Y coordinate of the upper left corner of the view
   */
  int y;
  /** The height of the view
   */
  int height;
  /** The width of the view
   */
  int width;
};

}  // namespace zombone_engine

#endif
