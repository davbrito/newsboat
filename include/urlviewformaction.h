#ifndef NEWSBOAT_URLVIEWFORMACTION_H_
#define NEWSBOAT_URLVIEWFORMACTION_H_

#include "formaction.h"
#include "htmlrenderer.h"
#include "listwidget.h"

namespace newsboat {

class UrlViewFormAction : public FormAction {
public:
	UrlViewFormAction(View*,
		std::shared_ptr<RssFeed>& feed,
		std::string formstr,
		ConfigContainer* cfg);
	~UrlViewFormAction() override;
	void prepare() override;
	void init() override;
	KeyMapHintEntry* get_keymap_hint() override;
	void set_links(const std::vector<LinkPair>& l)
	{
		links = l;
	}
	std::string id() const override
	{
		return "urlview";
	}
	std::string title() override;
	void handle_cmdline(const std::string& cmd) override;

private:
	bool process_operation(Operation op,
		bool automatic = false,
		std::vector<std::string>* args = nullptr) override;
	void update_heading();

	std::vector<LinkPair> links;
	bool quit;
	std::shared_ptr<RssFeed> feed;
	ListWidget urls_list;
};

} // namespace newsboat

#endif /* NEWSBOAT_URLVIEWFORMACTION_H_ */
