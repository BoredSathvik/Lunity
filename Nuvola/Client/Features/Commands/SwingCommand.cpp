#include "SwingCommand.h"

#include "../../../Utils/Utils.h"
#include "../../Bridge/LocalPlayer.h"
#include "../../Bridge/GuiData.h"

SwingCommand::SwingCommand() : Command("swing") {

}

auto SwingCommand::Execute(std::vector<std::string> params) -> bool {
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;

	player->swing();

	return true;
};

auto SwingCommand::GetDescription() -> std::string {
	return "Arbitrarily swings your arm";
}