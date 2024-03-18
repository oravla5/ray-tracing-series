#include "hittable/hittable_list.hpp"

namespace raytrc {

void HittableList::add(std::shared_ptr<Hittable> object)
{
    mObjects.push_back(object);
}

void HittableList::clear()
{
    mObjects.clear();
}

bool HittableList::hit(const Ray &ray, const Range &hitRange, HitResult &res) const
{
    HitResult latesResult;
    bool hitFlag = false;
    double closestHit = hitRange.max();

    for (const auto &object : mObjects) {
        if (object->hit(ray, Range{hitRange.min(), closestHit}, latesResult)) {
            hitFlag = true;
            closestHit = latesResult.t;
            res = latesResult;
        }
    }

    return hitFlag;
}
} // namespace raytrc