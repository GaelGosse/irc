/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2024/02/21 05:39:09 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a la fin de chaque commande faut mettre control+V suivit de contol+m
	// j'ai l'impression que c pas le cas dans tous les repo
	// en fait suffit de faire en sorte de regarder que \n et ça va fonctionner sans control machin


// voir si dans les autres repo aussi quand j'envoi des fausses commande nc quitte
	// ne quitte pas dans les autre repo




// envoyer command partielle
	// quand j'envoie control D ça prend bien seulement en compte les derniers truc que g tapé meme si g pas effacer le precedent
	// voir comment ça fonctionne dans les autre repo
		// j'ai l'impression que ignore et au final ne prend que le dernier truc
		// en fait quand je fais control D ça bloque le terminal et je peux pas supp le prec
		// je peux seulement continuer a ecrire et si je met pas un espace entre le nom de la command et larg ça fonctionne pas
		// du coup normalement notre truc devrait déjà fonctionner
			//on prend juste la dernière et on sfait pas chier, a tester
			// en fait je peux pas tester car nc quitte avant après un NI ctr+D et CK ctr+ D
			// régler ça et normalement ça devrait fonctionner
			// en fait il faut que je vois ce que les repo recoivent et envoi a chaque requete nc
			// comme ça je sais ce qu'ils envoient pour pas qu'il quitte
				// ma théorie c que a chaque message qu'il reçoit il envoi un truc et si nc
				// ne recoit pas de message pendant un certain nbr de message il quitte
				// en fait g capté c pas une question d'envoi
				// c jujste que mon program va pas à la suite quand il voit pas d'espace
				// et si je rajoute un espace bah meme si il fait r bah ça fonctionne
				// du coup faut que j'arrive à gérer si ya pas d'espacde
			// g reussi a gerer les fausses commandes sans quitter
			//voir pk control D 2 fois fait quitter
			//en fait la je peux fgaire autant de control D que je veux
			// mais ça sépare bien les commande lol
			// comment regrouper le tout ?
			//tester avec plusieurs command



			// g l'impression qu'il envoi rien bizzare, suivre le parcours du message dan sle code clbouche
			//yanou les commande fractionné ont tout cours l'air de pas de fonctionner, retester avec puis voir parcours du message
			// tester avec d'autre repo

		// faire en sorte que quand je quitte avec nc de manière inoipiné le client est deco

	// faire strategie pour tout recouper
// faire test sujet de correction

#ifndef COMMAND_HPP
#define COMMAND_HPP

# define CLRF	"\r\n"
//# define SERVER_NAME				"ircserv"
# define SERVER_NAME				"localhost"
//# define SERVER_HOSTNAME			std::string(SERVER_NAME) + ".fr"
#define SERVER_HOSTNAME				std::string("localhost")
# define SERVER_VERSION				"v4.2"
# define CHANNEL_MODES				"klnt"
# define USER_MODES					"io"
# define RPL_PREFIX(code, nick)		std::string(":" + SERVER_HOSTNAME + " " + code + " " + nick)
# define CLIENT_ID(nickname, username, command) (":" + nickname + "!~" + username + "@" + SERVER_NAME + " " + command + " ")


//		RPL
# define RPL_WELCOME(nick, user, host)			RPL_PREFIX("001", nick) + " :Welcome to the " + SERVER_NAME + " Network, " + nick + "!" + user + "@" + host + CLRF
# define RPL_YOURHOST(nick)						RPL_PREFIX("002", nick) + " :Your host is " + SERVER_HOSTNAME + ", running version " + SERVER_VERSION + CLRF
# define RPL_CREATED(nick, datetime)			RPL_PREFIX("003", nick) + " :This server was created " + datetime + CLRF
# define RPL_MYINFO(nick)						RPL_PREFIX("004", nick) + " " + SERVER_HOSTNAME + " " + SERVER_VERSION + " " + USER_MODES + " " + CHANNEL_MODES + CLRF
# define RPL_UMODEIS(nick, modes)				RPL_PREFIX("221", nick) + " :" + modes + CLRF
# define RPL_AWAY(nick, senderNick, msg)		RPL_PREFIX("301", nick) + " " + senderNick + " " + msg + CLRF
# define RPL_CHANNELMODEIS(channel, mode)		RPL_PREFIX("324", "") + " " + channel + " " + mode + " " + CLRF
# define RPL_NOTOPIC(nick, chan)				RPL_PREFIX("331", nick) + " " + chan + " :No topic is set" + CLRF
# define RPL_TOPIC(nick, chan, topic)			RPL_PREFIX("332", nick) + " " + chan + " :" + topic + CLRF
# define RPL_NAMREPLY(nick, chan, names)		RPL_PREFIX("353", nick) + " = " + chan + " :" + names + CLRF
# define RPL_ENDOFNAMES(nick, chan)				RPL_PREFIX("366", nick) + " " + chan + " :End of /NAMES list" + CLRF
# define RPL_YOUREOPER(nick)					RPL_PREFIX("381", nick) + " :You are now an IRC operator" + CLRF
# define RPL_QUIT(nick, senderNick, msg)		RPL_PREFIX("999", nick) + " :" + senderNick + " " + msg + CLRF

//		ERROR
# define ERR_NOSUCHNICK(nick, errNick)				RPL_PREFIX("401", nick) + " " + errNick + " :No such nick" + CLRF
# define ERR_NOSUCHCHANNEL(nick, chan)				RPL_PREFIX("403", nick) + " " + chan + " :No such channel" + CLRF
# define ERR_CANNOTSENDTOCHAN(nick, chan)			RPL_PREFIX("404", nick) + " " + chan + " :Cannot send to channel" + CLRF
# define ERR_TOOMANYTARGETS(nick)					RPL_PREFIX("407", nick) + " :Too many targets" + CLRF
# define ERR_NORECIPIENT(nick, command)				RPL_PREFIX("411", nick) + " :No recipient given (" + command + ")" + CLRF
# define ERR_NOTEXTTOSEND(nick)						RPL_PREFIX("412", nick) + " :No text to send" + CLRF
# define ERR_UNKNOWNCOMMAND(nick, command)			RPL_PREFIX("421", nick) + " :" + command + " :Unknown command" + CLRF
# define ERR_NONICKNAMEGIVEN(nick)					RPL_PREFIX("431", nick) + " :No nickname given" + CLRF
# define ERR_ERRONEUSNICKNAME(nick, errNick)		RPL_PREFIX("432", nick) + " " + errNick + " :Erroneous nickname" + CLRF
# define ERR_NICKNAMEINUSE(nick, errNick)			RPL_PREFIX("435", nick) + " " + errNick + " :Nickname is already in use" + CLRF
# define ERR_USERNOTINCHANNEL(nick, userNick, chan)	RPL_PREFIX("441", nick) + " " + chan + " " + userNick + " :They aren't on that channel" + CLRF
# define ERR_NOTONCHANNEL(nick, chan)				RPL_PREFIX("442", nick) + " :" + chan + " :You're not on that channel" + CLRF
# define ERR_NEEDMOREPARAMS(nick, cmd)				RPL_PREFIX("461", nick) + " :" + cmd + " :Not enough parameters" + CLRF
# define ERR_ALREADYREGISTRED(nick)					RPL_PREFIX("462", nick) + " :Unauthorized command (already registered)" + CLRF
# define ERR_PASSWDMISMATCH(nick)					RPL_PREFIX("464", nick) + " :Password incorrect" + CLRF
# define ERR_CHANNELISFULL(nick, chan)				RPL_PREFIX("471", nick) + " " + chan + " :Cannot join channel (+l)" + CLRF
# define ERR_BANNEDFROMCHAN(nick, chan)				RPL_PREFIX("474", nick) + " " + chan + " :Bannded from channel (+b)" + CLRF
# define ERR_BADCHANNELKEY(nick, chan)				RPL_PREFIX("475", nick) + " " + chan + " :Cannot join channel (+k)" + CLRF
# define ERR_NOPRIVILEGES(nick)						RPL_PREFIX("481", nick) + " :Permission Denied- You're not an IRC operator" + CLRF
# define ERR_CHANOPRIVSNEEDED(channel)				RPL_PREFIX("482", "") + channel + " :You're not channel operator\r\n"
# define ERR_NOOPERHOST(nick)						RPL_PREFIX("491", nick) + " :No O-lines for your host" + CLRF
# define ERR_UMODEUNKNOWNFLAG(target)				RPL_PREFIX("501", "") + " " + target + " :Unknown MODE flag" + CLRF
# define ERR_USERSDONTMATCH(target)					RPL_PREFIX("502", "") + " " + target + " :Cant change mode for other users" +  CLRF
#define PONG(nickname) (std::string(":") + SERVER_NAME + " PONG " + SERVER_NAME + " :" + SERVER_NAME + "\r\n")

# define ERR_UNKNOWNMODE(nick, chan)				RPL_PREFIX("472", nick) + " " + chan + " is unknown mode char to me" + CLRF
# define ERR_INVITEONLYCHAN(nick, channel)			(std::string(":") + SERVER_NAME + " 473 " + nick + " " + channel + " :Cannot join channel (+i)\r\n")
# define MODE_CHANNEL_NEWMDP(nickname, username, channel, mode, pass)		(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " password is now :" + pass + "\r\n")
# define MODE_CHANNEL_CLEARMDP(nickname, username, channel, mode)			(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " password is now erased" + "\r\n")
# define MODE_CHANNEL_NOWOP(nickname, username, channel, mode, name)		(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " " + name + " is now an operator" + "\r\n")
# define MODE_CHANNEL_NOMOREOP(nickname, username, channel, mode, name)		(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " " + name + " is no longer an operator" + "\r\n")
# define MODE_CHANNEL_CLIENTLIMIT(nickname, username, channel, mode, nb)	(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " " + "client limit is now " + nb + "\r\n")
# define MODE_CHANNEL_NOCLIENTLIMIT(nickname, username, channel, mode)		(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " " + "no more client limit" + "\r\n")
# define MODE_CHANNEL_NO_INVITE(nickname, username, channel, mode) 			(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " " + "(invite_only) remove " + "\r\n")
# define MODE_CHANNEL_YES_INVITE(nickname, username, channel, mode)			(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " " + "(invite_only) add. The channel is now in restricted mode." + "\r\n")

# define MODE_UNKNOW_MODE(nickname, username, channel, mode)				(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " is unknown mode char to me" + "\r\n")
# define MODE_TOPIC_OFF(nickname, username, channel, mode)					(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " Only operators can now change channel's topic." + "\r\n")
# define MODE_TOPIC_ON(nickname, username, channel, mode)					(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " Channel's topic can now be change by everyone." + "\r\n")

# define MODE_NEEDMOREPARAMS(nickname, username, channel, mode)				(CLIENT_ID(nickname, username, "MODE")  + channel + " " + mode + " Error. Need more prarameters." + "\r\n")

// # define NOTONCHANNEL(nickname, username, channel) 							(CLIENT_ID(nickname, username, "") + channel + " Error. You are not on that channel.\r\n")
#define NOTONCHANNEL(nickname, username, channel) 							(std::string(":") + SERVER_NAME + " 442 " + nickname + " " + channel + " :You are not on that channel\r\n")

# define NOSUCHCHANNEL(nickname, username, channel)							(CLIENT_ID(nickname, username, "") + " " + channel + " Error. No such channel." + "\r\n")
// # define TOPIC_IS_OFF(nick, chan)											(std::string(":") + SERVER_NAME + " " + nick + " :Topic changes desabled on " + chan + " !" + CLRF)
# define ERR_USERONCHANNEL(nickname, username, channel, name)				(CLIENT_ID(nickname, username, "") + " 443 " + channel + " " + name + " :is already on channel." + "\r\n")
// # define ERR_NOSUCHNICK(nickname, username, name)							(RPL_PREFIX("401", nickname) + " " + name + " :no such nick" + "\r\n")
# define INVITE_ON_CHAN(nickname, username, channel, name)					(CLIENT_ID(nickname, username, "") + " " + name + " You are invited on " + channel + " by " + nickname + "\r\n")
# define NEEDMOREPARAMS(nickname, username, cmd)							(CLIENT_ID(nickname, username, "")  + cmd + " Error. Need more prarameters." + "\r\n")
# define PRIVMSG_CHAN(nickname, username, dest, msg) 						(CLIENT_ID(nickname, username, "PRIVMSG") + dest + " :" + msg + "\r\n")
# define PART_CHAN(nickname, username, dest, msg) 							(CLIENT_ID(nickname, username, "PART") + dest + " :" + msg + "\r\n")




/* ---------------------------------- hinda ---------------------------------- */

#define REPLY_FORMAT(num_rply_numb, nickname) (std::string(":") + SERVER_NAME + " " + num_rply_numb + " " + nickname + " ")
#define CLIENT_ID(nickname, username, command) (":" + nickname + "!~" + username + "@" + SERVER_NAME + " " + command + " ")
#define user_id(nickname, username) (":" + nickname + "!" + username + "@localhost")
// 000
#define XRPL_WELCOME(nickname) (std::string(":") + SERVER_NAME + " 001 " + nickname + " :Welcome to the  " + SERVER_NAME + " Server " + nickname + "\r\n")

// 200
#define XRPL_UMODEIS(nickname, mode) (std::string(":") + SERVER_NAME + " 221 " + nickname + " " + mode + "\r\n")

// 300
#define XRPL_WHOISUSER(nickname, username, hostname, realname) (std::string(":") + SERVER_NAME + " 311 " + nickname + " " + username + " " + hostname + " * :" + realname + "\r\n")
#define XRPL_WHOISSERVER(nickname, servername, serverinfo) (std::string(":") + SERVER_NAME + " 312 " + nickname + " " + servername + " :" + serverinfo + "\r\n")
#define XRPL_ENDOFWHOIS(nickname) (std::string(":") + SERVER_NAME + " 318 " + nickname + " :End of /WHOIS list" + "\r\n")
#define XRPL_NOTOPIC(nickname, channel) (std::string(":") + SERVER_NAME + " 331 " + nickname + " #" + channel + " :No topic is set" + "\r\n")
#define XRPL_TOPIC(nickname, channel, topic) (std::string(":") + SERVER_NAME + " 332 " + nickname + " #" + channel + " :" + topic + "\r\n")
#define XROL_TOPICWHOTIME(nickname, channel, concerned_client_nickname, time) (std::string(":") + SERVER_NAME + " 333 " + nickname + " " + channel + " " + concerned_client_nickname + " " + time + "\r\n")
#define XRPL_INVITING(nickname, target, channel) (std::string(":") + SERVER_NAME + " 341 " + nickname + " " + target + " " + channel + "\r\n")
#define XRPL_NAMREPLY(nickname, channel, list_client) (std::string(":") + SERVER_NAME + " 353 " + nickname + " = " + channel + " :" + list_client  + "\r\n")
#define XRPL_ENDOFNAMES(nickname, channel) (std::string(":") + SERVER_NAME + " 366 " + nickname + " " + channel + " :End of /NAMES list" + "\r\n")
#define XRPL_INFO(nickname) (std::string(":") + SERVER_NAME + " 371 " + nickname + " :" + SERVER_NAME + "\r\n" + \
							":" + SERVER_NAME + " 371 " + nickname + " :" + "written by hinda, imen, marine" + "\r\n" + \
							":" + SERVER_NAME + " 371 " + nickname + " :" + "version 1.0" + "\r\n")
#define XRPL_ENDOFINFO(nickname) (std::string(":") + SERVER_NAME + " 374 " + nickname + " " + ":End of /INFO list. " + "\r\n")
#define XRPL_YOUROPER(nickname) (std::string(":") + SERVER_NAME + " 381 " + nickname + " :You are now an IRC operator" + "\r\n")
// 300
#define XRPL_WHOREPLY(nickname, channel, username, hostname, server, nick, mode, realname) (std::string(":") + SERVER_NAME + " 352 " + nickname + " " + channel + " " + username + " " + hostname + " " + server + " " + nick + " " + mode + " :0 " + realname + "\r\n")
#define XRPL_ENDOFWHO(nickname, name) (std::string(":") + SERVER_NAME + " 315 " + nickname + " " + name + " :End of /WHO list.\r\n")

// 400

#define XERR_NOSUCHNICK(nickname, other_nickname) (std::string(":") + SERVER_NAME + " 401 " + nickname + " " + other_nickname + " :No such nick\r\n")
#define XERR_NOSUCHSERVER(nickname) (REPLY_FORMAT(" 402", nickname) + SERVER_NAME + " :" + ":No such server\r\n")
#define XERR_NOSUCHCHANNEL(nickname, channel) (std::string(":") + SERVER_NAME + " 403 " + nickname + " " + channel + " :No such channel" + "\r\n")
#define XERR_NOORIGIN(nickname) (std::string(":") + SERVER_NAME + " 409 " + nickname + " :Not enough parameters\r\n")
#define XERR_NONICKNAMEGIVEN(nickname) (std::string(":") + SERVER_NAME + " 431 " + nickname + " :No nickname given\r\n")
#define XERR_NICKNAMEINUSE(nickname) (std::string(":") + SERVER_NAME + " 433 " + nickname + " :Nickname is already in use\r\n")
#define XERR_USERNOTINCHANNEL(nickname, channel, concerned_client_nickname) (std::string(":") + SERVER_NAME + " 441 " + nickname + " " + concerned_client_nickname + " " + channel + " :They aren't on that channel" + "\r\n")
#define XERR_NOTONCHANNEL(nickname, channel) (std::string(":") + SERVER_NAME + " 442 " + nickname + " " + channel + " :You're not on that channel" + "\r\n")
#define XERR_USERONCHANNEL(nickname, channel, concerned_client_nickname) (std::string(":") + SERVER_NAME + " 443 " + nickname + " " + concerned_client_nickname + " #" + channel + " :is already on channel" + "\r\n")
#define XERR_NOTREGISTERED(nickname, command) (std::string(":") + SERVER_NAME + " 451 " + nickname + " " + command + " :You have not registered" + "\r\n")
#define XERR_INVITEONLYCHAN(nickname, channel) (std::string(":") + SERVER_NAME + " 473 " + nickname + " " + channel + " :Cannot join channel (+i)" + "\r\n")
#define XERR_NEEDMOREPARAMS(nickname, command) (std::string(":") + SERVER_NAME + " 461 " + nickname + " " + command + " :Not enough parameters\r\n")
#define XERR_ALREADYREGISTRED(nickname) (std::string(":") + SERVER_NAME + " 462 " + nickname + " :Already registred\r\n")
#define XERR_PASSWDMISMATCH(nickname) (std::string(":") + SERVER_NAME + " 464 " + nickname + " :Password incorrect" + "\r\n")
#define XERR_CHANNELISFULL(nickname, channel) (REPLY_FORMAT("471", nickname) + channel + " :Cannot join channel (+l)" + "\r\n")
#define XERR_BADCHANNELKEY(nickname, channel) (REPLY_FORMAT("475", nickname) + channel + " :Cannot join channel (+k)" + "\r\n")
#define XERR_NOPRIVILEGES(nickname) (std::string(":") + SERVER_NAME + " 481 " + nickname + " :Permission Denied- You're not an IRC operator" + "\r\n")
#define XERR_CHANOPRIVSNEEDED(channel, nickname) (std::string(":") + SERVER_NAME + " 482 " + nickname + " " + channel + " :You're not channel operator" + "\r\n")

#define XERR_UMODEUNKNOWNFLAG(nickname) (std::string(":") + SERVER_NAME + " 501 " + nickname + " :Unknown MODE flag" + "\r\n")
#define XERR_USERSDONTMATCH(nickname) (std::string(":") + SERVER_NAME + " 502 " + nickname + " :Cant change mode for other users\r\n")

//macro CMDS

//NICK
#define XNICK(nickname, username, new_nickname) (CLIENT_ID(nickname, username, "NICK") + ":" + new_nickname + "\r\n")
# define XERR_ERRONEUSNICKNAME(client, nickname) (":localhost 432 " + client + " " + nickname + " :Erroneus nickname\r\n")

#define XPONG(nickname) (std::string(":") + SERVER_NAME + " PONG " + SERVER_NAME + " :" + SERVER_NAME + "\r\n")
#define XJOIN(nickname, username, channel) (CLIENT_ID(nickname, username, "JOIN") + ":#" + channel + "\r\n").c_str()
#define XMODE_CHANNEL(nickname, username, channel, mode) (CLIENT_ID(nickname, username, "MODE") + "#" + channel + " " + mode + "\r\n")
#define XINVITE(nickname, username, target, channel) (CLIENT_ID(nickname, username, "INVITE") + target + " :#" + channel + "\r\n")
#define XTOPIC(nickname, username, channel, topic) (CLIENT_ID(nickname, username, "TOPIC") + "#" + channel + " :" + topic + "\r\n")
#define XMODE_USER(nickname, username, target, mode) (CLIENT_ID(nickname, username, "MODE") + target + " " + mode + "\r\n")
#define XPRIVMSG(nickname, username, dest, msg) (CLIENT_ID(nickname, username, "PRIVMSG") + dest + " :" + msg + "\r\n")
#define XQUIT(nickname, username, message) (CLIENT_ID(nickname, username, "QUIT") + ":" + message + "\r\n")
#define XNOTICE(nickname, username, dest, msg) (CLIENT_ID(nickname, username, "NOTICE") + dest + " :" + msg + "\r\n")
//PART
# define XRPL_PART(user_id, channel, reason) (user_id + " PART #" + channel + " " + (reason.empty() ? "." : reason ) + "\r\n")
# define XKICK(nickname, username, channel, target, message) (CLIENT_ID(nickname, username, "KICK") + "#" + channel + " " + target + " :" + message + "\r\n")
# define XRPL_PRIVMSG(nick, username, target, message) (":" + nick + "!" + username + "@localhost PRIVMSG " + target + " " + message + "\r\n")
/* ---------------------------------- hinda ---------------------------------- */




#include "server.hpp"

class client;
class Server;
class channel;

class command {

	public:
		command();
		command(const command& copy);
		command& operator=(const command& copy);
		~command();

		int				OPER(int fd, Server* serv);
		int				WALLOPS(int fd, Server* serv);
		int				KICK(int fd, Server* serv);
		int				NOTICE(int fd, Server *serv);
		int				KILL(int fd, Server *serv);

		std::string		PASS(int fd, Server *serv);
		std::string		NICK(int fd, Server *serv);
		std::string		USER(int fd, Server *serv);
		std::string		PING(int fd, Server *serv);
		//std::string		PONG();
		std::string		QUIT(int fd, Server* serv);
		int				TOPIC(client *client1, Server *serv);
		int				MODE(client *client1, Server *serv);
		int				JOIN(client *client1, Server *serv);
		int				INVITE(client *client1, Server *serv);
		int				PRIVMSG(client *client1, Server *serv);
		int				PART(client *client1, Server *serv);

		std::string		bot();

		std::vector<std::string>	parsTemp(std::vector<std::string> temp);

		int	handleCmd(client *client1, Server *serv, std::string cmd);
		int			whatArg(std::vector<std::string> temp);
		int			whatSign(std::vector<std::string> temp);

};
#endif