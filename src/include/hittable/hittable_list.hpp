#ifndef INCLUDE_HITTABLE_HITTABLE_LIST_HPP
#define INCLUDE_HITTABLE_HITTABLE_LIST_HPP

#include <memory>
#include <vector>

#include "hittable/hittable.hpp"

namespace raytrc {

class HittableList : public Hittable {
public:
    HittableList() = default;

    void add(std::shared_ptr<Hittable> object);
    void clear();

    bool hit(const Ray &ray, const Range &hitRange, HitResult &res) const override;

private:
    std::vector<std::shared_ptr<Hittable>> mObjects;
};

} // namespace raytrc

#endif // INCLUDE_HITTABLE_HITTABLE_LIST_HPP