#pragma once

/**
	\file
	\brief Пример шаблона "Стратегия"
*/

#ifndef STRATEGY_STRATEGY_H
#define STRATEGY_STRATEGY_H

#include <vector>
#include <limits>
#include <memory>

namespace Strategy {

using IndexType = size_t;

template<typename T>
class BinarySearchStrategy {
protected:
	const std::vector<T>& m_items;

public:
	BinarySearchStrategy(const std::vector<T>& items) :
		m_items(items) {}

	virtual IndexType Find(const T& target, IndexType& left, IndexType& right) const = 0;
};

template<typename T>
class SearchElement : public BinarySearchStrategy<T> {
public:
	SearchElement(const std::vector<T>& items) :
		BinarySearchStrategy<T>(items) {}

	virtual IndexType Find(const T& target, IndexType& left, IndexType& right) const override {
		while (left <= right) {
			IndexType num = ((target - this->m_items[left]) * static_cast<T>(right - left));
			IndexType den = this->m_items[right] - this->m_items[left];
			IndexType middle = den ? (left + num / den) : left;

			if (this->m_items[middle] < target) {
				left = middle + 1;
			} else if (this->m_items[middle] > target) {
				right = middle - 1;
			} else {
				return middle;
			}
		}

		return std::numeric_limits<IndexType>::max();
	}
};

template<typename T>
class SearchFirstOccurrence : public BinarySearchStrategy<T> {
public:
	SearchFirstOccurrence(const std::vector<T>& items) :
		BinarySearchStrategy<T>(items) {}

	virtual IndexType Find(const T& target, IndexType& left, IndexType& right) const override {
		IndexType result = right;

		while (left < right) {
			IndexType middle = left + (right - left) / 2;

			if (this->m_items[middle] == target) {
				result = middle;
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}

		return result;
	}
};


/**
	\brief Класс-обертка над контейнером vector

	Класс-обертка над контейнером vector для бинарного поиска по элементам.
*/
template<typename T>
class BinarySearch {
private:
	const std::vector<T>& m_items;
	std::shared_ptr<BinarySearchStrategy<T>> m_bss;

public:
	BinarySearch(const std::vector<T>& items) :
		m_items(items),
		m_bss(new SearchElement<T> { m_items }) {}

	IndexType Find(const T& item) {
		IndexType result = std::numeric_limits<IndexType>::max();

		if (!m_items.empty()) {
			IndexType left = 0;
			IndexType right = m_items.size() - 1;

			result = m_bss->Find(item, left, right);

			if (result != std::numeric_limits<IndexType>::max() && left < result) {
				m_bss.reset(new SearchFirstOccurrence<T> { m_items });
				result = m_bss->Find(item, left, result);
				m_bss.reset(new SearchElement<T> { m_items });
			}
		}

		return result;
	}
};


} // namespace Strategy

#endif // !STRATEGY_STRATEGY_H
